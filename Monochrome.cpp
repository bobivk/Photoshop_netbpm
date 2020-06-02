#include "Monochrome.h"
string Monochrome::get_name() const {
	return "monochrome";
}

void Monochrome::execute(vector<Image*>& images){
	for (size_t i = 0; i < images.size(); ++i) {
		int pixel_max_value = images[i]->get_max_pixel_value();
		if (dynamic_cast<PBM_image*>(images[i])) {
			cout << "image " << images[i]->get_file_name() << " is already monochrome.\n";
		}
		else if (dynamic_cast<PGM_image*>(images[i])) {
			PGM_image* pgmimage = dynamic_cast<PGM_image*>(images[i]);
			vector<vector<PGM_pixel>> pixels = pgmimage->get_pixel_matrix();
			for (unsigned row = 0; row < pgmimage->get_dimensions().y; ++row) {
				vector<PGM_pixel> row_pixels = pixels[row];
				for (unsigned col = 0; col < pgmimage->get_dimensions().x; ++col) {
					if (row_pixels[col].value < pixel_max_value / 2) {
						//set either to maxvalue or 0
						row_pixels[col].value = 0;
					}
					else row_pixels[col].value = pixel_max_value;
				}
				pixels[row] = row_pixels;
			}
			pgmimage->set_pixel_matrix(pixels);
		}
		else if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			vector<vector<PPM_pixel>> pixels = ppmimage->get_pixel_matrix();
			for (unsigned row = 0; row < ppmimage->get_dimensions().y; ++row) {
				vector<PPM_pixel> row_pixels = pixels[row];
				for (unsigned col = 0; col < ppmimage->get_dimensions().x; ++col) {
					//set either to maxvalue or 0
					if (row_pixels[col].red < pixel_max_value / 2) {
						row_pixels[col].red = 0;
					}
					else row_pixels[col].red = pixel_max_value;
					if (row_pixels[col].blue < pixel_max_value / 2) {
						row_pixels[col].blue = 0;
					}
					else row_pixels[col].blue = pixel_max_value;
					if (row_pixels[col].green < pixel_max_value / 2) {
						row_pixels[col].green = 0;
					}
					else row_pixels[col].green = pixel_max_value;
				}
				pixels[row] = row_pixels;
			}
			ppmimage->set_pixel_matrix(pixels);
		}
	}
}