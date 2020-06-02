#include "Grayscale.h"

string Grayscale::get_name() const {
	return "grayscale";
}
void Grayscale::execute(vector<Image*>& images) {
	for (size_t i = 0; i < images.size(); ++i) {
		if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			vector<vector<PPM_pixel>> pixels = ppmimage->get_pixel_matrix();
			for (unsigned row = 0; row < ppmimage->get_dimensions().y; ++row) {
				vector<PPM_pixel> row_pixels = pixels[row];
				for (unsigned col = 0; col < ppmimage->get_dimensions().x; ++col) {
					int gray = (row_pixels[col].red +
								row_pixels[col].blue +
								row_pixels[col].green) / 3;
					cout << "gray: " << gray << ",";
					row_pixels[col].red = gray;
					row_pixels[col].blue = gray;
					row_pixels[col].green = gray;
				}
				pixels[row] = row_pixels;
			}
			ppmimage->set_pixel_matrix(pixels);
		}
		else {
			cout << "Image " << images[i]->get_file_name() << " is already grayscale.\n";
		}
	}
}