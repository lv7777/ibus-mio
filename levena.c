
//TODO:move to levena.c
//ibus.hにはibusengine.hやらglibc.hやらがincludeされてる
#include<ibus.h>

typedef struct tagIBusLevenaEngine IBusLevenaEngine;
typedef struct tagIBusLevenaEngineClass IBusLevenaEngineClass;

struct tagIBusLevenaEngine{
    IBusEngine parent;
};

struct tagIBusLevenaEngineClass{
    IBusEngineClass parent;
};

//catch the process-key-event signal from ibus_init
gboolean levena_process_key_event(IBusEngine *ie,guint keyval,guint keycode,guint state,gpointer user_data){

printf("process-key-event signal recieved!! : %x",keycode);
gboolean ret=0;
return TRUE;
}


int main(int argc,char **argv){

ibus_init();//絶対必要っぽい。忘れてた。

//必要なibus_系の宣言
IBusBus *bus;
IBusFactory *factory;
//component: imeエンジンの説明、作者、バージョン等。通常xmlから読み込む
IBusComponent *component;

//カスタムIMEのエンジンの追加。こいつをIBusEngineClassに変換する。
IBusLevenaEngineClass *levenaengine;
//process_key_event登録用のエンジンクラス。詳細不明
IBusEngineClass *iec;
gchar *IMEname="ibus-levena";


bus=ibus_bus_new();
factory=ibus_factory_new(ibus_bus_get_connection(bus));
//todo:下の理解。ime側エンジンなのこれ、imエンジンなの？
ibus_factory_create_engine(factory,IMEname);

iec=IBUS_ENGINE_CLASS (levenaengine);
iec->process_key_event=levena_process_key_event;

//最後にして至高の一撃、ibus_main()
ibus_main();
}