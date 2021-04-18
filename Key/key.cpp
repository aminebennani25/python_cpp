#include <pybind11/pybind11.h>
#include "micro-ecc/uECC.h"

class Key
{
	private:
        std::string PublicKey;
        std::string PrivateKey;

    public:

        void initialize(std::string number) 
        { 
			PrivateKey = number;

			const uint8_t* k = reinterpret_cast<const uint8_t*>(PrivateKey.c_str());
			const int SizePublicKey=uECC_curve_public_key_size(uECC_secp256k1());
			
			uint8_t *instancePublicKey = new uint8_t(SizePublicKey);
			
			uECC_compute_public_key(k,instancePublicKey,uECC_secp256k1());
			
			PublicKey=std::string( instancePublicKey, instancePublicKey+SizePublicKey );
		}
		
        std::string getPrivateKey()
        { 
        	return PrivateKey; 
        }
		
		std::string getPublicKey()
		{ 
			return PublicKey; 
		}


};
 
namespace py = pybind11;


PYBIND11_MODULE(key, k)
{
    py::class_<Key>(k, "Key", py::dynamic_attr())
        .def(py::init())
        .def("initialize", &Key::initialize)
        .def("getPrivateKey", &Key::getPrivateKey)
        .def("getPublicKey", &Key::getPublicKey);
}

