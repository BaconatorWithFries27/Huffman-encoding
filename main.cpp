#include <cstdlib> 
#include <iostream>
#include <vector>
#include "inputProcessing.cpp"
#include "makeBitstream.cpp"
#include "BitStringDecoder.cpp"
#include <chrono>
#include "TestText.cpp"
using namespace std;
using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();

    string input;

    cout << "Enter text to process: \n";\

    //getline(cin, input);
    
    // ezpz
    input = "the quick brown fox jumps over the lazy dog.";
    
    // hard mode
    //input = "Lorem ipsum odor amet, consectetuer adipiscing elit. Tincidunt aliquam vel fermentum egestas mollis purus donec nascetur egestas. Lectus phasellus mi erat cubilia fames purus morbi montes. Consequat dignissim aliquam feugiat turpis pulvinar. Ut ultricies turpis sagittis proin justo eget etiam himenaeos. At morbi himenaeos dis nisi elementum scelerisque bibendum. Elementum aliquam bibendum auctor dui curae feugiat pharetra potenti. Senectus convallis integer ridiculus class porttitor ac leo vivamus. Eu magna tincidunt parturient sagittis vel suspendisse. Lacus morbi aptent malesuada nascetur facilisi erat habitant praesent nibh. Rhoncus facilisis luctus felis torquent pellentesque lectus. Quam ultrices lobortis fusce molestie maximus risus congue; vitae metus. Penatibus nibh taciti placerat penatibus bibendum sodales. Diam blandit praesent natoque imperdiet sed aptent ac porta. Mauris suspendisse iaculis vulputate ridiculus netus platea mattis neque. Praesent potenti aptent malesuada, habitant posuere ipsum. Vitae congue hac vitae nullam eu odio et. Justo ac nulla placerat in fringilla. Mi nullam consequat pulvinar urna penatibus. Sociosqu nec nisi duis justo risus phasellus mattis lectus ullamcorper. Fermentum ad imperdiet nunc nulla sagittis orci tempor bibendum. Metus vehicula eu ultricies dolor magna tincidunt suspendisse ultricies. Luctus leo magna mauris suscipit vel. Rutrum rutrum dis nunc eget eleifend. Cubilia semper duis morbi tellus nostra sed. Lobortis cursus tellus vestibulum nullam bibendum. Erat proin libero tempor; ornare condimentum tempus. Et dictumst fames cubilia, varius dis velit. Efficitur taciti parturient potenti a ligula. Vivamus bibendum suspendisse consequat elit et erat. Aptent tellus lacinia leo arcu litora praesent ante mus. Rhoncus mattis sodales netus laoreet eros etiam congue. Lacus bibendum pharetra a nam id posuere mollis sem. Cursus interdum ac suspendisse enim ante ultrices sodales facilisi. Ridiculus integer habitasse ligula mauris proin odio. Maximus gravida phasellus potenti commodo cras dui curabitur. Sodales dolor inceptos mauris himenaeos penatibus habitasse.";
    
    // harder mode
    //input = "Lorem ipsum odor amet, consectetuer adipiscing elit. Maximus suscipit diam sollicitudin luctus; ad eget. Fermentum lobortis nulla euismod odio suscipit adipiscing. Praesent nulla ullamcorper ridiculus vestibulum enim scelerisque. Interdum velit vehicula urna, enim non pellentesque. Facilisis per taciti taciti euismod feugiat lorem. Leo est aenean inceptos; magnis tempor himenaeos.Elit cubilia primis ex aptent imperdiet maximus viverra pretium. Nascetur cras praesent facilisis tortor fames platea. Vivamus eleifend eu justo; accumsan congue consectetur. Habitasse euismod senectus curabitur per varius per faucibus. Faucibus himenaeos penatibus volutpat; libero nunc luctus dui. Tellus volutpat efficitur sociosqu platea hendrerit nulla cursus fermentum dictumst. Velit volutpat ante fermentum commodo accumsan in montes.Volutpat primis nec vitae diam faucibus nibh blandit suspendisse. Egestas sodales felis risus platea blandit sociosqu maximus netus. Volutpat placerat felis platea cras arcu natoque ac a. Interdum faucibus dui convallis gravida fringilla orci tincidunt efficitur. Mauris cras blandit ullamcorper adipiscing sem enim. Accumsan ornare senectus est ridiculus mollis quam. Ex accumsan id sodales augue himenaeos.Eu senectus dictum ex parturient blandit lobortis, cras penatibus. Penatibus ad rutrum ullamcorper amet vestibulum interdum. Odio lectus nostra nam; vitae tristique risus. Sed etiam sit accumsan condimentum fringilla est; nisi magna. Auctor diam senectus, aliquam pretium quis maximus. Commodo vestibulum id mauris mattis tellus semper convallis ante scelerisque. Mauris vitae mi vivamus ipsum libero penatibus sem. Egestas pretium libero primis in dignissim litora varius. Pretium lectus mi taciti nec scelerisque pellentesque senectus.Praesent at gravida egestas euismod ad. Velit imperdiet fames integer fames praesent quam. Aptent nibh vulputate commodo lorem habitant curabitur mollis. Varius litora etiam bibendum arcu ultrices cras donec etiam. Sociosqu ligula phasellus mollis venenatis elementum sagittis finibus senectus. Torquent fames vitae tincidunt blandit tincidunt platea. Cursus quisque tristique duis quam nibh praesent. Mus elit arcu odio non dolor sem pharetra. Sapien efficitur at scelerisque dis inceptos dictum fusce.Condimentum conubia dictumst scelerisque pretium placerat enim. Sit auctor lobortis tempus tempor nulla duis. Euismod rutrum cras commodo magna enim porta. Aenean auctor id molestie eu elit pretium maecenas ut in. Sodales cursus pretium erat maecenas nulla. Orci himenaeos eu orci, blandit molestie lectus a. Magnis viverra aenean ac sem; nunc fringilla eleifend. Est parturient sociosqu sagittis curae efficitur convallis.Senectus faucibus non; praesent fusce vehicula risus aptent at tristique. Lobortis diam facilisis vel sodales integer ridiculus rhoncus. Primis urna adipiscing platea in scelerisque consectetur. Morbi sociosqu sodales urna ex varius; ex turpis. Aptent venenatis tellus parturient molestie, ultricies mollis erat. Aliquet dapibus laoreet vivamus nascetur ornare posuere in lacinia. Consequat commodo tortor mollis nisi id ipsum rutrum. Euismod potenti facilisis; elementum fringilla ultrices etiam cubilia. Mollis hendrerit ut augue nulla semper dictum.Felis potenti nisl massa himenaeos urna. Vulputate taciti mus morbi integer, eleifend integer cubilia. Fermentum sociosqu metus id finibus facilisis. Posuere maximus pretium auctor ipsum sed ultrices vitae dui. Potenti imperdiet purus mauris elit vestibulum lacus auctor. Id hendrerit etiam felis primis arcu natoque suscipit. Tristique ante et tellus venenatis ullamcorper nec velit in. Fames facilisi gravida magnis odio eu vivamus.Elementum montes dapibus maximus hendrerit habitant sem. Per malesuada risus ridiculus ipsum gravida eget natoque gravida. Quam euismod fames dis massa amet class felis volutpat. Ullamcorper curae senectus odio nibh rutrum tempor facilisi quisque. Maecenas class luctus erat sollicitudin mus ligula orci morbi. Cubilia molestie consectetur arcu proin massa quam. Fermentum imperdiet leo suscipit phasellus sed ad. Blandit nascetur viverra finibus risus faucibus diam faucibus.Fermentum tristique nunc fames habitant ante ultricies ridiculus gravida. Leo eleifend ullamcorper inceptos hac aenean. Aenean montes himenaeos faucibus senectus eleifend? Fames sollicitudin dolor neque nostra lacinia pretium; elit ridiculus. Nam luctus pellentesque potenti magnis tellus ultrices cursus nec a. Tempus ridiculus sociosqu fames molestie quam nisl. Apellentesque rutrum nibh himenaeos; tortor dapibus tempus.";
    
    cout << input << endl;


    std::cout << "input length: " << input.length() << endl;

    /* Ask inputProcessing to parse the input string into a freqArr ->
     * 1. Vector of all the character in the string,
     * 2. Vector of frequency of occurrence of all characters in the string.
     */
    freqArr completedArrays = parseString(input);

    printArr(completedArrays);

    int size = completedArrays.chars.size();

    // Build the huffman tree from the above freqArr struct
    struct MinHeapNode* root = buildHuffmanTree(completedArrays.chars, completedArrays.freqs, size);

    int intarr[MAX_TREE_HT], top = 0; 

	printCodes(root, intarr, top);

    // TODO: take the bitstream and break it into chunks and process those seperately for parallelism reasons
        // like take the input and break it into a fixed length and make more calls to the decoder?

    // Convert the input string into a bitstream using the above huffman tree.
    string bitstream = makeBitString(root, input, completedArrays.freqs);


    std::cout << std::dec << bitstream << endl;
    
    std::cout << "bitstring length: " << bitstream.length() << endl;
    
    cout<< "Beginning decoding process..." << endl;


    decode(bitstream, root);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nRun time is: " << duration.count() << " microseconds" << endl;

}