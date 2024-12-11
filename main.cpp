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
    //input = "the quick brown fox jumps over the lazy dog.";
    
    // hard mode
    //input = "Lorem ipsum odor amet, consectetuer adipiscing elit. Tincidunt aliquam vel fermentum egestas mollis purus donec nascetur egestas. Lectus phasellus mi erat cubilia fames purus morbi montes. Consequat dignissim aliquam feugiat turpis pulvinar. Ut ultricies turpis sagittis proin justo eget etiam himenaeos. At morbi himenaeos dis nisi elementum scelerisque bibendum. Elementum aliquam bibendum auctor dui curae feugiat pharetra potenti. Senectus convallis integer ridiculus class porttitor ac leo vivamus. Eu magna tincidunt parturient sagittis vel suspendisse. Lacus morbi aptent malesuada nascetur facilisi erat habitant praesent nibh. Rhoncus facilisis luctus felis torquent pellentesque lectus. Quam ultrices lobortis fusce molestie maximus risus congue; vitae metus. Penatibus nibh taciti placerat penatibus bibendum sodales. Diam blandit praesent natoque imperdiet sed aptent ac porta. Mauris suspendisse iaculis vulputate ridiculus netus platea mattis neque. Praesent potenti aptent malesuada, habitant posuere ipsum. Vitae congue hac vitae nullam eu odio et. Justo ac nulla placerat in fringilla. Mi nullam consequat pulvinar urna penatibus. Sociosqu nec nisi duis justo risus phasellus mattis lectus ullamcorper. Fermentum ad imperdiet nunc nulla sagittis orci tempor bibendum. Metus vehicula eu ultricies dolor magna tincidunt suspendisse ultricies. Luctus leo magna mauris suscipit vel. Rutrum rutrum dis nunc eget eleifend. Cubilia semper duis morbi tellus nostra sed. Lobortis cursus tellus vestibulum nullam bibendum. Erat proin libero tempor; ornare condimentum tempus. Et dictumst fames cubilia, varius dis velit. Efficitur taciti parturient potenti a ligula. Vivamus bibendum suspendisse consequat elit et erat. Aptent tellus lacinia leo arcu litora praesent ante mus. Rhoncus mattis sodales netus laoreet eros etiam congue. Lacus bibendum pharetra a nam id posuere mollis sem. Cursus interdum ac suspendisse enim ante ultrices sodales facilisi. Ridiculus integer habitasse ligula mauris proin odio. Maximus gravida phasellus potenti commodo cras dui curabitur. Sodales dolor inceptos mauris himenaeos penatibus habitasse.";
    
    // harder mode
    //input = "Lorem ipsum odor amet, consectetuer adipiscing elit. Maximus suscipit diam sollicitudin luctus; ad eget. Fermentum lobortis nulla euismod odio suscipit adipiscing. Praesent nulla ullamcorper ridiculus vestibulum enim scelerisque. Interdum velit vehicula urna, enim non pellentesque. Facilisis per taciti taciti euismod feugiat lorem. Leo est aenean inceptos; magnis tempor himenaeos.Elit cubilia primis ex aptent imperdiet maximus viverra pretium. Nascetur cras praesent facilisis tortor fames platea. Vivamus eleifend eu justo; accumsan congue consectetur. Habitasse euismod senectus curabitur per varius per faucibus. Faucibus himenaeos penatibus volutpat; libero nunc luctus dui. Tellus volutpat efficitur sociosqu platea hendrerit nulla cursus fermentum dictumst. Velit volutpat ante fermentum commodo accumsan in montes.Volutpat primis nec vitae diam faucibus nibh blandit suspendisse. Egestas sodales felis risus platea blandit sociosqu maximus netus. Volutpat placerat felis platea cras arcu natoque ac a. Interdum faucibus dui convallis gravida fringilla orci tincidunt efficitur. Mauris cras blandit ullamcorper adipiscing sem enim. Accumsan ornare senectus est ridiculus mollis quam. Ex accumsan id sodales augue himenaeos.Eu senectus dictum ex parturient blandit lobortis, cras penatibus. Penatibus ad rutrum ullamcorper amet vestibulum interdum. Odio lectus nostra nam; vitae tristique risus. Sed etiam sit accumsan condimentum fringilla est; nisi magna. Auctor diam senectus, aliquam pretium quis maximus. Commodo vestibulum id mauris mattis tellus semper convallis ante scelerisque. Mauris vitae mi vivamus ipsum libero penatibus sem. Egestas pretium libero primis in dignissim litora varius. Pretium lectus mi taciti nec scelerisque pellentesque senectus.Praesent at gravida egestas euismod ad. Velit imperdiet fames integer fames praesent quam. Aptent nibh vulputate commodo lorem habitant curabitur mollis. Varius litora etiam bibendum arcu ultrices cras donec etiam. Sociosqu ligula phasellus mollis venenatis elementum sagittis finibus senectus. Torquent fames vitae tincidunt blandit tincidunt platea. Cursus quisque tristique duis quam nibh praesent. Mus elit arcu odio non dolor sem pharetra. Sapien efficitur at scelerisque dis inceptos dictum fusce.Condimentum conubia dictumst scelerisque pretium placerat enim. Sit auctor lobortis tempus tempor nulla duis. Euismod rutrum cras commodo magna enim porta. Aenean auctor id molestie eu elit pretium maecenas ut in. Sodales cursus pretium erat maecenas nulla. Orci himenaeos eu orci, blandit molestie lectus a. Magnis viverra aenean ac sem; nunc fringilla eleifend. Est parturient sociosqu sagittis curae efficitur convallis.Senectus faucibus non; praesent fusce vehicula risus aptent at tristique. Lobortis diam facilisis vel sodales integer ridiculus rhoncus. Primis urna adipiscing platea in scelerisque consectetur. Morbi sociosqu sodales urna ex varius; ex turpis. Aptent venenatis tellus parturient molestie, ultricies mollis erat. Aliquet dapibus laoreet vivamus nascetur ornare posuere in lacinia. Consequat commodo tortor mollis nisi id ipsum rutrum. Euismod potenti facilisis; elementum fringilla ultrices etiam cubilia. Mollis hendrerit ut augue nulla semper dictum.Felis potenti nisl massa himenaeos urna. Vulputate taciti mus morbi integer, eleifend integer cubilia. Fermentum sociosqu metus id finibus facilisis. Posuere maximus pretium auctor ipsum sed ultrices vitae dui. Potenti imperdiet purus mauris elit vestibulum lacus auctor. Id hendrerit etiam felis primis arcu natoque suscipit. Tristique ante et tellus venenatis ullamcorper nec velit in. Fames facilisi gravida magnis odio eu vivamus.Elementum montes dapibus maximus hendrerit habitant sem. Per malesuada risus ridiculus ipsum gravida eget natoque gravida. Quam euismod fames dis massa amet class felis volutpat. Ullamcorper curae senectus odio nibh rutrum tempor facilisi quisque. Maecenas class luctus erat sollicitudin mus ligula orci morbi. Cubilia molestie consectetur arcu proin massa quam. Fermentum imperdiet leo suscipit phasellus sed ad. Blandit nascetur viverra finibus risus faucibus diam faucibus.Fermentum tristique nunc fames habitant ante ultricies ridiculus gravida. Leo eleifend ullamcorper inceptos hac aenean. Aenean montes himenaeos faucibus senectus eleifend? Fames sollicitudin dolor neque nostra lacinia pretium; elit ridiculus. Nam luctus pellentesque potenti magnis tellus ultrices cursus nec a. Tempus ridiculus sociosqu fames molestie quam nisl. Apellentesque rutrum nibh himenaeos; tortor dapibus tempus.";
    //input = "DogsCatsBirdTurtZebrFishShrkHawk";

    //harderer mode
    input = "Lorem ipsum odor amet, consectetuer adipiscing elit. Metus maecenas taciti aliquam pretium eleifend in tempor. Sed senectus placerat dictum accumsan; consectetur aliquam. Dis litora platea tristique ante porttitor congue varius primis. Eros porttitor tempor in taciti laoreet risus vel arcu enim. Nostra senectus eu sociosqu donec potenti. Conubia proin fringilla phasellus, ac donec hendrerit. Varius porttitor lacus a mi aenean viverra aenean. Ligula taciti per sodales libero blandit ridiculus aliquam. Mollis proin consequat molestie sociosqu purus nisl sit tempor. Curae iaculis vel ornare lobortis; phasellus enim lacus. Litora molestie habitasse facilisi cras bibendum duis. Pulvinar ac dignissim metus ridiculus nam litora sem eget. Arcu pellentesque convallis sodales lacus commodo adipiscing mollis congue. Egestas congue eu facilisi venenatis et lectus. Bibendum cursus tortor aptent lobortis lectus. Tincidunt orci litora non praesent potenti. Tempor lectus viverra; ridiculus cras auctor nec venenatis. Nisi nascetur imperdiet, efficitur vulputate tempor nascetur. Blandit nisl litora pulvinar tempus dis ultricies ultrices mus. Fusce montes dis aenean mauris gravida? Suspendisse fusce euismod faucibus mattis cras consectetur nec morbi. Tincidunt amet dignissim suspendisse ac egestas dapibus. Dignissim suspendisse amet commodo volutpat orci nisl fermentum varius nunc. Turpis etiam dignissim dolor inceptos risus. Nascetur conubia ac natoque morbi curabitur dignissim massa fermentum. Blandit nisl sed elementum ac tellus dictum. Aenean elementum eget posuere; class eros lectus. Massa penatibus orci tincidunt sollicitudin ac euismod dapibus sagittis natoque. Habitasse non libero dictum curabitur torquent curae facilisis faucibus. Diam senectus porttitor himenaeos mus, sapien bibendum inceptos finibus. Potenti risus tellus porttitor commodo accumsan sociosqu laoreet turpis. Pellentesque mattis malesuada ligula pharetra conubia metus vel. Conubia ligula porttitor rutrum, egestas dignissim cursus orci purus. Curabitur integer ornare proin nisl aliquet elementum ridiculus curae nostra. Scelerisque rutrum vivamus cursus sollicitudin per semper. Arcu consectetur habitant facilisis scelerisque sagittis hendrerit velit. Volutpat accumsan volutpat rutrum amet consequat, consequat volutpat. Auctor tempus sodales hendrerit massa; eleifend praesent. Convallis ad eu nec pretium luctus eget mi. Nibh porta in nisi sagittis turpis mauris vitae. Sodales vitae quam placerat vivamus scelerisque magnis at. Augue ultricies curae molestie efficitur vel suspendisse cubilia. Augue magnis aliquam nisl aliquam primis. Arcu mauris diam ornare efficitur himenaeos ridiculus molestie eleifend. Bibendum amet sem finibus suspendisse penatibus id. Fames cras mauris adipiscing pharetra; tempus curae dui diam. Suspendisse gravida a nascetur interdum per erat vel tempus. Non ad nec sed justo velit eget. Venenatis nunc penatibus magna posuere ultricies ipsum. Natoque sapien fringilla duis ipsum augue elementum blandit. Sagittis in lacus mattis magna laoreet nibh tempor sem. Ultrices facilisis interdum elementum fames dictum; tortor viverra. Semper litora class; imperdiet ex sit maximus ex malesuada. Natoque dignissim placerat eros elit ante at praesent interdum. Senectus tempus fusce quisque ante congue auctor. Primis himenaeos nulla convallis blandit ac nulla. Posuere laoreet nec himenaeos porta vehicula phasellus. Litora mollis vitae aenean dignissim natoque vehicula potenti? Penatibus velit eu metus gravida pretium; phasellus euismod aenean. Sollicitudin iaculis rutrum tortor phasellus fames proin hendrerit. Litora potenti vestibulum sociosqu iaculis vitae ornare rhoncus himenaeos sit. Conubia magnis netus potenti ad erat commodo accumsan magna. Nulla ornare cras lectus himenaeos phasellus sapien. Erat gravida malesuada ut eget per maecenas mus. Eleifend est augue varius porttitor luctus. Porta ridiculus ac, metus donec suscipit per urna iaculis. Scelerisque vestibulum fames egestas natoque pretium suspendisse rhoncus. Viverra sapien elementum ornare iaculis adipiscing sit tempor mollis. Condimentum at habitant tellus habitasse id. Metus feugiat aliquet id erat habitasse maximus. Diam pulvinar nisl vestibulum luctus est. Enim pellentesque sodales cras adipiscing, arcu mauris purus. Dis consequat cursus mauris fames dis nullam pretium praesent. Arcu litora elementum consequat iaculis sem fames elit. Aptent nullam elementum vitae diam donec libero. Arcu netus pharetra ligula rhoncus, vestibulum ad. Malesuada volutpat nostra netus orci ex est nunc vel nisl. Bibendum diam porta montes sem vitae condimentum nec magna ut. Finibus dolor natoque ligula molestie diam hac. Tellus placerat in lacus nec volutpat. Mattis mollis dictum suspendisse suscipit molestie hac eu. Consectetur habitasse massa congue a sodales eu. Quisque lacus montes sagittis taciti augue egestas rutrum magna. Metus penatibus magnis, erat sollicitudin tempus auctor. Ultricies urna aliquet massa sapien class netus magnis tempor. Nam maecenas ac nullam ut conubia? Per malesuada nisi enim suscipit erat bibendum velit tortor risus. Lectus metus at amet arcu volutpat ligula conubia. Fringilla fames sociosqu montes lacinia habitant tempus ante lorem bibendum. Laoreet porttitor amet consectetur aliquam sociosqu sit litora facilisi. Sed phasellus sodales scelerisque platea senectus. Mus porttitor nec aliquet et, tempus rutrum placerat adipiscing aliquam. Class litora mollis praesent eleifend torquent porta. Vel malesuada finibus convallis et dapibus sed facilisis. Ac massa parturient venenatis quam; aliquet nunc. Blandit penatibus quam habitasse posuere sagittis. Blandit in aliquet nostra tristique accumsan at facilisi luctus. Ligula maximus mattis; integer suscipit facilisis sem? Mattis taciti faucibus dapibus tempus nec. Parturient penatibus potenti; vivamus molestie laoreet lorem ac quam tristique. Facilisis lobortis tincidunt finibus etiam conubia vehicula suscipit. Cras libero semper etiam, adipiscing eu lacinia congue. Ullamcorper velit nulla netus tellus et finibus lectus. Pharetra suspendisse nunc pellentesque praesent etiam. Consequat suscipit elit netus ad sociosqu. Eros sem cubilia etiam vitae; penatibus platea etiam. Mi nisi lectus lacus in quis quam sed. Tortor tellus inceptos faucibus cubilia placerat velit natoque bibendum? Lectus taciti nisi netus facilisis et mauris bibendum ullamcorper. Lacus cubilia dictumst a vestibulum volutpat bibendum maecenas justo. Porta lacinia inceptos aptent tincidunt rutrum cras consequat non urna. Fusce facilisi donec nec fermentum tempor. Commodo erat facilisi dictum faucibus velit. In volutpat justo curae senectus rhoncus iaculis a turpis? Blandit augue finibus donec bibendum scelerisque nam vel suspendisse. Curae augue feugiat eget convallis senectus facilisi sit. Eget vivamus ultrices eu vehicula dictum nascetur, molestie auctor. Posuere tempor nulla efficitur sodales donec euismod faucibus himenaeos. Quam id sapien mollis auctor non fermentum dis varius. Sollicitudin dictumst ante integer vivamus consectetur facilisis. Tempus phasellus ultrices proin turpis sem massa fames nisi ridiculus. Rhoncus sapien nulla porttitor magna mi. Aenean nisi dis a ipsum sit luctus ante. Orci ligula habitasse ex, eu neque inceptos. Consectetur aliquet eget mus facilisi sapien est. Natoque at est volutpat posuere torquent massa amet. Duis blandit himenaeos turpis ut nunc vulputate. Augue leo orci nisl ex; praesent in tortor tristique. At iaculis habitasse at rutrum praesent cubilia mus iaculis. Mi ipsum purus nisi risus erat molestie torquent curabitur. Efficitur magnis maecenas bibendum; ex finibus nibh. Maecenas egestas habitant commodo sapien odio aptent posuere felis. Sodales arcu mi sit platea sociosqu senectus aptent lacinia. Ex leo semper ultrices efficitur rutrum mus. Urna semper facilisi placerat magna arcu tincidunt tempor taciti in. Ornare sociosqu facilisi aenean; sagittis sem tristique mi. Odio orci habitasse diam habitasse, molestie mollis. Lacus viverra nunc nisl mollis magnis congue. Curabitur mollis convallis; donec facilisi rhoncus nibh taciti. Curabitur potenti magnis per vulputate hac sit in habitant. Morbi aenean ornare sit; gravida id nostra. Magnis praesent enim congue vel id hendrerit eu etiam. Nisi eleifend ut augue nostra senectus habitasse. Arcu donec quam praesent nec nec. Dictum sit maecenas laoreet facilisis phasellus eros phasellus ex. Nam id torquent ad bibendum aliquet leo sapien tortor. Risus tempor dis vulputate volutpat maximus; ultrices risus. Etiam per eros hac nullam condimentum rutrum? Tincidunt cursus parturient, amet primis feugiat imperdiet tincidunt ut. Justo commodo nibh nunc efficitur vehicula. Dictum ex felis sollicitudin odio est efficitur. Vulputate bibendum ipsum pharetra auctor nec fames etiam. Blandit condimentum ultricies posuere aenean eget. Vulputate habitasse at; gravida euismod elementum platea penatibus euismod. Faucibus quam senectus, quisque enim urna cursus. Sollicitudin per risus vitae dictumst dui ullamcorper. Fringilla at lorem quisque posuere nunc fringilla. Nisi quisque vel, nunc sagittis lorem nostra. Dui scelerisque dapibus volutpat, tincidunt felis cubilia. Mattis donec tempus phasellus egestas, varius dignissim fermentum vestibulum. Natoque cras sapien inceptos pharetra duis nostra. Quis euismod urna sem mauris finibus sem scelerisque. Rhoncus ultricies finibus turpis fermentum nullam posuere mi iaculis. Sociosqu id per a augue nam. Finibus torquent dolor elit lectus fames. Neque taciti elit habitasse lobortis bibendum tortor a quam. Feugiat a consectetur nascetur porttitor eget ipsum fames tempor sociosqu! Lacinia pulvinar per class rutrum taciti lorem nisl. Sapien quisque porta amet tempor ad erat eget elementum condimentum. Eget nibh at fames nam vestibulum varius facilisi. Facilisis arcu adipiscing tincidunt, porta nascetur consequat posuere mauris elementum. Torquent tellus phasellus ullamcorper, duis viverra condimentum nulla. Fames in nam montes nunc ligula quam. Efficitur a diam primis condimentum ante? Diam risus cras suscipit inceptos torquent dui. Egestas porttitor faucibus scelerisque himenaeos bibendum gravida efficitur dolor. Mollis at risus praesent sollicitudin nulla dignissim et. Sollicitudin tempor curae mollis luctus senectus nunc bibendum taciti. Elit aptent hac erat placerat posuere condimentum? Nulla blandit mus nisl consequat aliquet fames. Condimentum lectus mattis sem non nibh posuere euismod torquent. Dui curabitur sociosqu habitasse dui morbi etiam montes ligula. Nec sit leo nec, sit mattis curae etiam. Facilisis libero mauris ligula magnis parturient nibh. Eros dolor at vel sodales dolor nostra. Finibus ad magnis est; aliquet venenatis cras adipiscing. Elementum gravida lobortis malesuada blandit aliquet nibh elit. Rhoncus tempor eu eleifend sollicitudin sapien risus rhoncus. Curabitur vel odio vulputate ipsum ullamcorper. Cras venenatis facilisi aptent; placerat proin per? Vel quis eu tellus velit proin eleifend blandit. Consectetur arcu mus sollicitudin orci; facilisis metus pretium. Viverra pulvinar a consequat metus pharetra amet scelerisque? Mi malesuada nibh metus, primis interdum rutrum malesuada vulputate auctor. Dignissim et suscipit nullam eget accumsan proin tellus. Pellentesque felis laoreet faucibus consectetur libero imperdiet. Hac mollis id nulla est id duis donec vitae. Aptent ipsum tincidunt purus molestie sociosqu semper donec conubia. Adipiscing magna posuere risus velit lacinia. Laoreet efficitur etiam mus turpis, vulputate id urna. Tempor ac cursus nullam egestas dapibus cubilia. At condimentum conubia convallis; finibus est nisi arcu arcu. Ac malesuada magna aptent himenaeos sed eu vehicula volutpat. Venenatis dapibus ipsum dictum; eget in metus. Quisque fames adipiscing ad velit ridiculus. Felis vivamus sit arcu viverra metus dictum ligula odio ridiculus. Primis ex a gravida felis enim aenean integer in. Erat litora purus lacus euismod dignissim curabitur arcu. Duis placerat ullamcorper arcu leo rhoncus turpis leo. Pretium inceptos hac primis bibendum integer mollis. Torquent curabitur lobortis rutrum venenatis orci nunc sociosqu. Tincidunt fusce tempor curabitur torquent natoque porta dictumst. Aliquam et convallis sem tristique nostra ornare commodo tempor. Faucibus quis iaculis conubia pellentesque ultrices vulputate non. Mi non mauris ridiculus porttitor, taciti facilisis primis turpis. Natoque est torquent vestibulum fermentum nec; pretium pulvinar. Inceptos dictum tristique fringilla quisque per, montes dictum suspendisse. Vitae ultrices libero dictum id maximus integer. Facilisis a mattis lacinia tellus tincidunt tempus odio ultricies adipiscing. Semper pharetra felis dis; pellentesque lacinia dapibus. Avel arcu maecenas ipsum vestibulum vestibulum nec. Purus porttitor tempor dignissim proin, lobortis praesent. Conubia quisque mus vehicula fusce nisi sagittis duis nec himenaeos. Dapibus senectus adipiscing nibh nascetur fermentum quisque. Proin sit nascetur sollicitudin posuere habitant suspendisse semper consectetur. Mollis ante fermentum ut ridiculus integer. Risus vel et nullam metus ultricies. Sed erat est semper eleifend fames, praesent dolor. Faucibus imperdiet ultrices cras viverra bibendum massa quis. Pharetra purus per tortor risus ipsum tortor nascetur ex. Bibendum ullamcorper ut diam ad ut odio euismod. Commodo sociosqu luctus in orci tortor cras. Nibh varius condimentum posuere sed porta orci. Elit magnis sit volutpat etiam aenean nunc. Euismod non penatibus pharetra integer posuere varius dapibus primis. Montes a interdum ac senectus; maximus lacus. Parturient nisi congue ipsum laoreet iaculis turpis fusce. Scelerisque ante ut maecenas, sociosqu mattis porttitor fusce purus. Scelerisque integer sociosqu condimentum luctus vitae ut neque. Morbi mattis senectus massa commodo facilisis tristique. Est est sociosqu placerat metus senectus; accumsan convallis purus. Fringilla scelerisque maecenas gravida senectus curae; ligula vel suspendisse id. Imperdiet sed pretium etiam quisque nibh arcu maximus semper. Neque porttitor lectus convallis sagittis ridiculus venenatis. Efficitur senectus mollis maecenas torquent feugiat rhoncus inceptos dis. Vitae est nostra ante orci praesent leo. Volutpat luctus dapibus pretium vitae eu facilisi. Leo urna consectetur ultrices ad nunc tempus natoque. Habitant porta ante semper libero platea. Commodo a faucibus vulputate quis lacinia sagittis augue. Vitae erat tortor tristique mi per fermentum vulputate. Pretium vestibulum ante elementum porttitor ad eu sed. Nullam nisl auctor ut natoque class metus maximus. Etiam dui urna sit; at etiam lectus. Feugiat libero commodo hac cubilia senectus molestie luctus. Fames justo hac quisque magna lorem aenean mollis a. Tempor fringilla viverra faucibus tortor pulvinar vulputate rutrum himenaeos diam. Dignissim dis phasellus ac vulputate enim dictumst ligula. Consequat gravida tincidunt convallis elit luctus penatibus. Aptent ac viverra odio, facilisis euismod in. Pharetra nibh pharetra dignissim; porttitor etiam felis himenaeos. Vitae facilisi finibus auctor suspendisse arcu pellentesque. Sociosqu non aptent elit orci purus fermentum libero. Maecenas commodo sodales adipiscing hendrerit maecenas bibendum. Iaculis quam hac blandit, ultricies tortor potenti turpis. Cursus suscipit donec rhoncus elementum urna facilisi urna. Ligula habitant mollis natoque nostra nunc adipiscing. Curae urna parturient enim ultricies proin. Suscipit sodales curabitur elit in mauris mollis malesuada vehicula? Sed arcu hendrerit lacinia laoreet malesuada. Viverra torquent lacus elementum enim vitae per hendrerit scelerisque a. Netus nulla dictum turpis potenti non justo. Sollicitudin sociosqu enim convallis luctus tempus morbi conubia sapien. Dui nulla ipsum eleifend nam gravida quam nam velit. Efficitur vulputate condimentum id suscipit orci. Finibus cras risus massa rhoncus pharetra montes gravida euismod. Ad posuere sodales curae hendrerit vehicula. Hac ac justo justo netus rhoncus primis lobortis pulvinar. Convallis nisi fames ornare, metus cras eget magna. Parturient nibh consequat dui platea lorem. Feugiat parturient ridiculus ultricies, leo commodo gravida eleifend tellus. Quisque adipiscing torquent facilisis maecenas massa condimentum dignissim tincidunt nulla. Curae libero ullamcorper auctor; pretium commodo ut maximus viverra. Sociosqu posuere ornare fames eros platea aliquet venenatis nisl risus. Vulputate ut lacus finibus aliquam venenatis ut suscipit. Dis vehicula erat eleifend; leo himenaeos sollicitudin penatibus rhoncus. Rhoncus iaculis varius vivamus donec vehicula. Per augue luctus hendrerit adipiscing etiam nullam suspendisse quisque. Eu feugiat aliquet, quam mus quisque mollis quam. Nisl placerat pellentesque porta nisi in. Taciti placerat sit nullam volutpat hendrerit eleifend. Vitae sodales praesent aliquet lectus nibh arcu rutrum dui. Commodo ut neque turpis commodo, bibendum conubia bibendum. Vitae iaculis senectus urna vivamus eleifend sit. Est fames commodo auctor; lobortis habitasse dolor erat maximus nibh. Convallis luctus in aliquam quam cras. Imperdiet torquent arcu elementum auctor facilisis, praesent nisi ut. Himenaeos nascetur varius placerat; ornare justo parturient eu. Faucibus id ultricies parturient, efficitur facilisis vitae. Nostra risus et natoque velit molestie donec eget aenean. Fusce integer eros habitasse quis posuere lacinia. Nostra imperdiet risus ullamcorper integer vitae pellentesque arcu. Nam ridiculus vel facilisis rutrum arcu auctor nullam. Eros auctor semper sed parturient laoreet. Potenti mus scelerisque montes dis ex vehicula taciti dolor. At lacus eget fames egestas ornare hac ornare class natoque. Non nibh sociosqu convallis parturient eleifend donec placerat morbi. Penatibus suspendisse urna faucibus mollis vel curabitur iaculis. Magnis eget tortor ut nascetur pretium dapibus dignissim aenean. Tempus sodales nisi cras nam ridiculus etiam? Ante ullamcorper mi rutrum gravida, nostra quam vel. Convallis sagittis imperdiet netus inceptos penatibus facilisis parturient. Platea in integer mus libero bibendum mauris auctor. Vestibulum velit mattis habitant adipiscing; mattis primis. Laoreet nascetur curabitur tincidunt semper aliquet blandit dolor. Mus lobortis inceptos penatibus egestas tristique sociosqu lacinia feugiat. Dapibus hendrerit aliquam dignissim nec mattis facilisis sagittis pretium libero. In id adipiscing cras primis laoreet sociosqu varius eros. Venenatis convallis parturient, consequat aenean vehicula tellus? Diam praesent ultrices lorem ipsum nisi. Enim ante sapien congue urna vulputate duis velit. Faucibus orci tincidunt netus interdum donec metus etiam. Diam curabitur efficitur dapibus sapien magnis malesuada. Curae nec turpis donec inceptos facilisis potenti; augue porta. Felis laoreet augue ex platea, odio est pretium. Lobortis nostra fringilla; laoreet mollis consectetur mus neque euismod. Id arcu pellentesque erat curabitur tristique. Quam pulvinar porttitor tortor himenaeos egestas interdum. Turpis rutrum nisl orci eros proin. Ullamcorper dapibus pharetra nam rhoncus pellentesque pretium scelerisque massa integer. Pharetra laoreet ligula mus nulla maecenas. Platea dis eleifend odio nam, vivamus nisi risus. Curae eleifend proin pharetra felis vehicula. Magna odio facilisi commodo faucibus arcu. Amet magnis faucibus eget congue convallis. Primis scelerisque facilisis pellentesque vivamus; inceptos mus sem scelerisque. Vulputate vulputate est dignissim aenean ullamcorper leo posuere curabitur mauris. Cubilia convallis parturient, sagittis habitasse taciti elementum molestie tincidunt facilisi.";

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
    auto stringstart = high_resolution_clock::now();
    
    string bitstream = makeBitString(root, input, completedArrays.freqs);


    std::cout << std::dec << bitstream << endl;
    
    std::cout << "bitstring length: " << bitstream.length() << endl;
    
    cout<< "Beginning decoding process..." << endl;


    decode(bitstream, root);

    auto stringstop = high_resolution_clock::now();

    auto uintstart = high_resolution_clock::now();

    uintStream bitvec = stringToVec(bitstream);

    uintDecode(bitvec, root);

    auto uintstop = high_resolution_clock::now();

    auto stop = high_resolution_clock::now();

    auto stringduration = duration_cast<microseconds>(stringstop - stringstart);

    auto duration = duration_cast<microseconds>(stop - start);

    auto uintduration = duration_cast<microseconds>(uintstop - uintstart);

    cout << "\nstring runtime is: " << stringduration.count() << " microseconds" << endl;

    cout << "\nuint runtime is: " << uintduration.count() << " microseconds" << endl;

    cout << "\nfull runtime is: " << duration.count() << " microseconds" << endl;

    cout << "Size of input: " << input.capacity() << " Size of bitstring: " << bitstream.capacity() << " Size of bitvec: " << bitvec.vec.capacity() * sizeof(uint64_t) << endl;
}