import pathlib
from setuptools import find_packages, setup

HERE = pathlib.Path(__file__).parent

VERSION = '0.0.1' #Importante cambiar la versión de la librería según se incluyan nuevas funcionalidades
PACKAGE_NAME = 'loggingrg' #Debe coincidir con el nombre de la carpeta 
AUTHOR = 'Rubén García García' 
AUTHOR_EMAIL = 'rubenggjac@gmail.com' 
URL = 'https://github.com/Rubens05' 

LICENSE = 'MIT' #Tipo de licencia
DESCRIPTION = 'Librería para la montirización y auditoría de placas en entornos IoT' #Descripción corta
LONG_DESCRIPTION = (HERE / "README.md").read_text(encoding='utf-8') #Referencia al documento README con una descripción más elaborada
LONG_DESC_TYPE = "text/markdown"


#Paquetes necesarios para que funcione la libreía. Se instalarán a la vez si no lo tuvieras ya instalado
INSTALL_REQUIRES = [
      'paho-mqtt',
      'logging',
      'time'
      ]

setup(
    name=PACKAGE_NAME,
    version=VERSION,
    description=DESCRIPTION,
    long_description=LONG_DESCRIPTION,
    long_description_content_type=LONG_DESC_TYPE,
    author=AUTHOR,
    author_email=AUTHOR_EMAIL,
    url=URL,
    install_requires=INSTALL_REQUIRES,
    license=LICENSE,
    packages=find_packages(),
    include_package_data=True
)