
/**
 *       @file  main.c
 *      @brief  Simulador de Auscultacção Pulmunar (Instruendo)
 *
 * 
 *
 *     @author  Mauro Antunes, mauroantunes@ua.pt
 *
 *   @internal
 *     Created  30-Jan-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2016, Mauro Antunes
 *
 * =====================================================================================
 */
 
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

/**
 *  @brief  Funcao main para criação do cliente e gestão da interface (GTK) 
 *  @param  argc: NULL
 *  @param  argv: NULL
 *	@return void 
 */
 
 
int main(int argc, char *argv[])
{
    char *outText;
        
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
   
    
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
	 
	 api->SetVariable("tessedit_char_whitelist", "0123456789");
	 
    // Open input image with leptonica library
    //Pix *image = pixRead("/home/bruno/TEST.png");
    Pix *image = pixRead(argv[1]);
    //printf("|%s|",argv[1]);
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
