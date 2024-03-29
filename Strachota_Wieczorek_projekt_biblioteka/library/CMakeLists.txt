cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES include/model/Client.h src/model/Client.cpp
        test/master.cpp include/typedefs.h include/model/ClientType.h src/model/ClientType.cpp src/model/Student.cpp include/model/Student.h src/model/Outsider.cpp include/model/Outsider.h src/model/universityEmployee.cpp include/model/universityEmployee.h src/model/Address.cpp include/model/Address.h test/AddressTest.cpp test/ClientTest.cpp src/exceptions/ClientException.cpp include/exceptions/ClientException.h include/repositories/Templates.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h test/ClientRepositoryTest.cpp src/managers/ClientManager.cpp include/managers/ClientManager.h test/ClientManagerTest.cpp src/model/RentableItem.cpp include/model/RentableItem.h src/model/Article.cpp include/model/Article.h src/model/Book.cpp include/model/Book.h src/model/Rent.cpp include/model/Rent.h test/RentTest.cpp test/BookTest.cpp test/ArticleTest.cpp src/repositories/RentRepository.cpp include/repositories/RentRepository.h src/repositories/RentableItemRepository.cpp include/repositories/RentableItemRepository.h test/RentableItemRepositoryTest.cpp test/RentRepositoryTest.cpp src/managers/RentManager.cpp include/managers/RentManager.h test/RentManagerTest.cpp include/model/FunctorPredicates.h src/managers/RentableItemManager.cpp include/managers/RentableItemManager.h test/RentableItemManagerTest.cpp src/exceptions/RentExceptions.cpp include/exceptions/RentExceptions.h src/exceptions/RentableItemException.cpp include/exceptions/RentableItemException.h include/model/Observers.h)

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES} include/model/Client.h src/model/Client.cpp)

target_include_directories(Library PUBLIC include)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)


#set(SOURCE_TEST_FILES include/model/Client.h src/model/Client.cpp test/master.cpp include/typedefs.h include/model/ClientType.h src/model/ClientType.cpp src/model/Student.cpp include/model/Student.h src/model/Outsider.cpp include/model/Outsider.h src/model/universityEmployee.cpp include/model/universityEmployee.h src/model/Address.cpp include/model/Address.h test/AddressTest.cpp test/ClientTest.cpp src/exceptions/ClientException.cpp include/exceptions/ClientException.h include/repositories/Templates.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h test/ClientRepositoryTest.cpp src/managers/ClientManager.cpp include/managers/ClientManager.h test/ClientManagerTest.cpp test/RentTest.cpp test/BookTest.cpp test/ArticleTest.cpp test/RentRepositoryTest.cpp test/RentableItemRepositoryTest.cpp test/RentManagerTest.cpp)

set(SOURCE_TEST_FILES include/model/Client.h src/model/Client.cpp test/master.cpp include/typedefs.h include/model/ClientType.h src/model/ClientType.cpp src/model/Student.cpp include/model/Student.h src/model/Outsider.cpp include/model/Outsider.h src/model/universityEmployee.cpp include/model/universityEmployee.h src/model/Address.cpp include/model/Address.h test/AddressTest.cpp test/ClientTest.cpp src/exceptions/ClientException.cpp include/exceptions/ClientException.h include/repositories/Templates.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h test/ClientRepositoryTest.cpp src/managers/ClientManager.cpp include/managers/ClientManager.h test/ClientManagerTest.cpp test/RentTest.cpp test/BookTest.cpp test/ArticleTest.cpp test/RentRepositoryTest.cpp test/RentableItemRepositoryTest.cpp test/RentManagerTest.cpp src/managers/RentManager.cpp include/managers/RentManager.h include/model/FunctorPredicates.h src/managers/RentableItemManager.cpp include/managers/RentableItemManager.h test/RentableItemManagerTest.cpp include/model/Observers.h) # tu w przyszłości będą dodawane pliki źródłowe testów


add_executable (LibraryTest ${SOURCE_TEST_FILES} include/model/Client.h src/model/Client.cpp test/master.cpp)

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})