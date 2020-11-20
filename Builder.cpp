//BenjaminKramer
//11/19/2020
#include <iostream>
using namespace std;

//An illustration of how two builder design patterns work

//Your end product 
class AppleProduct{
    string _product;
    string _input;
    string _processor;

public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setInput(string set_input) { _input = set_input; }
    string getProcessor() { return _processor; }
    string getInput() { return _input; }
    
    void show() {
    	cout << "Apple Base Product Info: " <<_product << endl;
      cout << "Input Type: " <<_input << endl;
    	cout << "Processor Type: "<<_processor << endl << endl;
    }
};

//Your end jobApplication
class AppleJobApplication{
    string _application;
    string _input;
    string _requirements;

public:

    AppleJobApplication(string set_application) { _application = set_application; }

    void setRequirements(string set_requirements) { _requirements = set_requirements; }

    void setInput(string set_input) { _input = set_input; }
    string getRequirements() { return _requirements; }
    string getInput() { return _input; }
    
    void show() {
    	cout << "Default Info: " <<_application << endl;
      cout << "Input Name and Email: " <<_input << endl;
    	cout << "Requirements: "<<_requirements << endl << endl;
    }
};

//AppleProductBuilder Abstract Class all builders 
//should have at least these methods
class AppleProductBuilder{
protected:
    AppleProduct *_apple_product;
public:
    virtual void getOtherParts() = 0;
    virtual void buildInput() = 0;
    virtual void buildProcessor() = 0;
    AppleProduct* getAppleProduct(){ return _apple_product; }
};
//AppleJobApplicationBuilder Abstract Class all builders 
//should have at least these methods
class AppleJobApplicationBuilder{
protected:
    AppleJobApplication *_apple_job_application;
public:
    virtual void getApplication() = 0;
    virtual void buildInput() = 0;
    virtual void buildRequirements() = 0;
    AppleJobApplication* getAppleJobApplication(){ return _apple_job_application; }
};

//AppleJobApplicationBuilder concrete class knows only how to
//build softwareEngineer AppleJobApplication!
class softwareEngineerBuilder: public AppleJobApplicationBuilder {

public:

    void getApplication() { _apple_job_application = new AppleJobApplication("Your LinkedIn Profile has populated in"); }

    void buildRequirements() { _apple_job_application->setRequirements("Resume and Transcript");   }

    void buildInput() { _apple_job_application->setInput("Your Name and Email");   }
};

//AppleJobApplicationBuilder concrete class knows only how to
//build humanResources AppleJobApplication!
class humanResourcesBuilder: public AppleJobApplicationBuilder {

public:

    void getApplication() { _apple_job_application = new AppleJobApplication("Your LinkedIn Profile has populated in"); }

    void buildRequirements() { _apple_job_application->setRequirements("Resume and Transcript");   }

    void buildInput() { _apple_job_application->setInput("Your Name and Email");   }
};

//AppleProductBuilder concrete class knows only how to 
//build iPhone AppleProduct!
class iPhoneBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }
};

//AppleProductBuilder concrete class knows only how to 
//build Mac AppleProduct!
class MacBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input");   }
};
//AppleProductBuilder concrete class knows only how to 
//build iPad AppleProduct!
class iPadBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPad"); }

    void buildProcessor() { _apple_product->setProcessor("Apple A8X Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }
};
//AppleProductBuilder concrete class knows only how to 
//build iPad Pro AppleProduct
class iPadProBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPad Pro"); }

    void buildProcessor() { _apple_product->setProcessor("Apple M10 Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen and Apple Pen Input");   }
};
// Defines steps and tells to the builder that build in given order.
class Director{

    AppleProductBuilder *builder;
    AppleJobApplicationBuilder *apbuilder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder *builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        return builder->getAppleProduct();
    }
    AppleJobApplication* createAppleJobApplication(AppleJobApplicationBuilder *apbuilder) {
        apbuilder->getApplication();
        apbuilder->buildInput();
        apbuilder->buildRequirements();
        return apbuilder->getAppleJobApplication();
    }
};

int main() {
	
  Director dir;
  MacBuilder mb;
  iPhoneBuilder ib;
  iPadBuilder ipb;
  iPadProBuilder ippb;
  softwareEngineerBuilder seb;
  humanResourcesBuilder hrb;
  

	AppleProduct *mac = dir.createAppleProduct(&mb);
	AppleProduct *iphone = dir.createAppleProduct(&ib);
  AppleProduct *ipad = dir.createAppleProduct(&ipb);
  AppleProduct *ipadpro = dir.createAppleProduct(&ippb);

  AppleJobApplication *softwareengineer = dir.createAppleJobApplication(&seb);
  AppleJobApplication *humanresources = dir.createAppleJobApplication(&hrb);
	
	mac->show();
  delete mac;

	iphone->show();
  delete iphone;

  ipad->show();
  delete ipad;  

  ipadpro->show();
  delete ipadpro;

  softwareengineer->show();
  delete softwareengineer;

  humanresources->show();
  delete humanresources;
    
	return 0;
}
