
#include <iostream>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;

	void *handle1;
	void *handle2;

	handle1 = dlopen(argv[1],RTLD_LAZY);
	handle2 = dlopen(argv[2],RTLD_LAZY);

	if(handle1==NULL){
		std::cerr<<"dlopen: " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}

	if(handle2==NULL){
		std::cerr<<"dlopen : "<< dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	int (*composant1)(int,int) =(int (*)(int,int))dlsym(handle1,"composant1");
	if(composant1 == NULL){
		std::cerr <<"dlsym: " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	int ( *composant2)(int,int) =(int (*)(int,int))dlsym(handle2,"composant2");
	if(composant2==NULL){
		std::cerr << "dlsym : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}


	valeur1=composant1(data1,data2);

	valeur2=composant2(data1,data2);

	//std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
	dlclose(handle1);
	dlclose(handle2);
	return EXIT_SUCCESS;


}

