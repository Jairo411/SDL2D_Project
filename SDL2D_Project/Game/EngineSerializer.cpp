#include "EngineSerializer.h"
#include "../GameObjects/GameObject.h"

Serializer* Serializer::instance = nullptr;

Serializer::Serializer()
{
	//Just creating every file, not handling any of the files
	//intializing my std::map variable
	CurrentDoc = new pugi::xml_document();
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/EngineData", "/EngineData.xml"));
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Game/Scenes", "/SceneData.xml"));
	directorydictionary.insert(std::make_pair("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData", "/GameObjectData.xml"));
	struct stat status;
	std::map <const char*, const char*>::iterator it = directorydictionary.begin();
	int count = 0;
	while (it != directorydictionary.end())
	{
		if (std::filesystem::exists(it->first) == false)
		{
			std::cout << it->first << std::endl;
			std::cout << "Directory doesn't exist, creating it..." << std::endl;

			std::filesystem::create_directory(it->first);
			std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
			pugi::xml_document* temp = DefaultSerialized(docRootNames[count]);
			auto rootNode = temp->child(docRootNames[count]);
			// just some const char handling 
			std::string path = it->first;
			std::string file = it->second;
			std::string combined = path + file;


			temp->save_file(combined.c_str(), PUGIXML_TEXT(""));
			documentList.insert(std::make_pair(temp, rootNode));
		}
		else
		{
			//Files don't get re-written if they exist
			std::string path = it->first;
			std::string file = it->second;
			std::string combined = path + file;
			// this checks to see if the files exist themselves  
			// if they don't exist
			if (stat(combined.c_str(), &status) != 0)
			{
				std::cout << "Creating Files, currentFile being created :" << docRootNames[count] << std::endl;
				pugi::xml_document* temp;
				temp = DefaultSerialized(docRootNames[count]);
				auto rootNode = temp->child(docRootNames[count]);
				documentList.insert(std::make_pair(temp, rootNode));
				temp->save_file(combined.c_str(), PUGIXML_TEXT(""));
			}
			// if they do they get loaded in
			else if (stat(combined.c_str(), &status) == 0)
			{
				std::cout << "Loading in Files...." << std::endl;
				std::string path = it->first;
				std::string file = it->second;
				std::string combined = path + file;
				pugi::xml_document* temp = new pugi::xml_document();

				temp->load_file(combined.c_str());

				auto rootNode = temp->child(docRootNames[count]);
				documentList.insert(std::make_pair(temp, rootNode));
			}
		}
		count++;
		it++;
	}
	
}

Serializer* Serializer::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new Serializer();
	}
	return instance;
}

Serializer::~Serializer()
{
	CurrentDoc = nullptr;
	delete CurrentDoc;
}



pugi::xml_document* Serializer::GameObjectSerializer(GameObject* OBJ_)
{
	return 	DefaultSerialized(OBJ_->nameID);
}

pugi::xml_document* Serializer::DefaultSerialized(std::string tag_)
{
	/* SO THIS IS ALWAYS THE DEFAULT*/
	pugi::xml_document* temp = new pugi::xml_document();

	auto declarationNode = temp->append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = 1.0f;
	declarationNode.append_attribute("encoding") = "ISO-8859-1";
	auto root = temp->append_child(pugi::node_element).set_name(tag_.c_str());

	return temp;
}

bool Serializer::isChildNodeExist(const char* nodeName_)
{
	if (CurrentDoc->child(nodeName_) != NULL)
	{
		return true;
	}

	return false;
}

bool Serializer::SceneExist(int SceneIndex_, const char* SceneName_)
{
	pugi::xml_node root = CurrentDoc->next_sibling();
	std::cout << root.name() << std::endl;
	for (pugi::xml_node node : root.child(SceneName_) )
	{
		std::cout << node.name() << std::endl;
		system("pause");
	}
	return false;
}

bool Serializer::loadFile(const char* FileDirectory_)
{
	
	pugi::xml_parse_result result = CurrentDoc->load_file(FileDirectory_);
	std::cout << "Load results: " << result.description() << std::endl;
	return result;
}



void Serializer::Print()
{
	pugi::xml_node_iterator it = CurrentDoc->begin();

	for (auto depth0 : CurrentDoc->first_child())
	{
		std::cout << "Current Node" << depth0.name() << std::endl;
		std::cout << "Current Node attributes: " << depth0.first_attribute().name() << depth0.first_attribute().value() << std::endl;
		for (auto depth1 : CurrentDoc->next_sibling())
		{
			std::cout << "Current Node" << depth1.name() << std::endl;
			std::cout << "Current Node attributes: " << depth1.first_attribute().name() << depth0.first_attribute().value() << std::endl;
		}
	}
}

void Serializer::AddAnimationState(GameObject* OBJ_, const char* imageSrc_)
{

	std::map<pugi::xml_document*, pugi::xml_node>::iterator it;

	std::string path = "/GameObjectsData.xml";
	std::string combinedPath = SerializedGameObjectInfo + path;
	std::string flag = "GameObject";
	struct stat status;

	//Creates new file
	//if (stat(combinedPath.c_str(), &status) != 0)
	//{
	//	if (std::filesystem::exists("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData") == false)
	//	{
	//		std::cout << "directory doesn't exist, creating a new one";
	//		std::filesystem::create_directory("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/GameObjects/GameObjectData");
	//	}

	//	std::cout << "This file doesn't exist, creating a new one " << std::endl;

	//	CurrentDoc = DefaultSerialized("GameObjectsInfo");

	//	auto GameObjectNode = CurrentDoc.child("GameObjectsInfo").append_child(pugi::node_element);
	//	GameObjectNode.set_name("GameObject");
	//	GameObjectNode.append_attribute("GameObjectID ") = OBJ_->nameID.c_str();
	//	
	//	auto AnimationNode=GameObjectNode.append_child(pugi::node_element);
	//	AnimationNode.set_name("AnimationInfo");
	//	AnimationNode.append_attribute("AmountOfAnimationSets") = 0;
	//	auto childAnimation = AnimationNode.append_child(pugi::node_element);

	//	std::string set = "AnimationSet"; 
	//	std::string combined= set + AnimationNode.first_attribute().value();

	//	childAnimation.set_name(combined.c_str());

	//	auto IMGSrc=childAnimation.append_child(pugi::node_element);
	//	
	//	IMGSrc.set_name("IMGSrc");
	//	IMGSrc.append_child(pugi::node_pcdata).set_value(imageSrc_);
	//	
	//	lastNodeElement = IMGSrc;

	//	bool save = CurrentDoc.save_file(combinedPath.c_str(), PUGIXML_TEXT(""));
	//} //Loads File 
	//else if (stat(combinedPath.c_str(), &status) == 0)
	//{
	//	std::string lastAnimationSet;
	//	result = CurrentDoc.load_file(combinedPath.c_str());
	//	std::cout << "load results: " << result.description() << std::endl;


	//	auto parentOfLastNode = CurrentDoc.child("AnimationInfo");
	//	int count=0;

	//	
	//	
	//}
}
void Serializer::CreateScene(int currentScene_, const char* sceneName_)
{
	/*I need to load the file if it exist*/
	loadFile(fullpath[2]);
	if (SceneExist(currentScene_,sceneName_)==false)
	{
		std::multimap<pugi::xml_document*, pugi::xml_node>::iterator it0 = documentList.begin();
	std::map <const char*, const char*>::iterator it1 = directorydictionary.begin();

	for (int i = 0; i < 1; i++)
	{
		it0++;
		it1++;
	}

	if (isChildNodeExist("ScenesInfo") == true)
	{

		auto rootNode = CurrentDoc->child("ScenesInfo");

		auto sceneNode = rootNode.append_child(pugi::node_element);
		sceneNode.set_name("Scene");
		sceneNode.append_attribute("SceneNumber ") = currentScene_;
		sceneNode.append_attribute("SceneName ") = sceneName_;


		std::string path = it1->first;
		std::string fileName = it1->second;
		std::string combined = path + fileName;

		CurrentDoc->save_file(combined.c_str(), PUGIXML_TEXT(""));

	}
}

}

