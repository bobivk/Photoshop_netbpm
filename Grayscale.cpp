#include "Grayscale.h"

string Grayscale::get_name() const {
	return "grayscale";
}
void Grayscale::execute(vector<Image*>& images) {
	for (size_t i = 0; i < images.size(); ++i) {
		if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			for (size_t row = 0; row < ppmimage->dimensions.x; ++row) {
				for (size_t col = 0; col < ppmimage->dimensions.y; ++col) {
					int gray = (ppmimage->pixel_matrix[row][col].red +
								ppmimage->pixel_matrix[row][col].blue +
								ppmimage->pixel_matrix[row][col].green) / 3;
					ppmimage->pixel_matrix[row][col].red = gray;
					ppmimage->pixel_matrix[row][col].blue = gray;
					ppmimage->pixel_matrix[row][col].blue = gray;
				}
			}
		}
		else {
			cout << "Image " << images[i]->get_file_name() << " is already grayscale.\n";
		}
	}
}