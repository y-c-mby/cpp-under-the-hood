#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>
int default_text_formatter_ider_text_id;
int default_text_formatter_ider_next_id = 0;
//int DefaultTextFormatter::Ider::next_id = 0;
//using std::printf;

////// DefaultTextFormatter Defs ////////////

//DefaultTextFormatter::DefaultTextFormatter()
//:   id(Ider::getId())
//{
//    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", id);
//}
void init_default_text_formmater(default_text_formmaterptr this){
    this->id = default_text_formatter_ider_next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
//DefaultTextFormatter::DefaultTextFormatter(const DefaultTextFormatter& other)
//:   id(Ider::getId())
//{
//    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other.id, id);
//}
void init_default_text_formmater_dtf(default_text_formmaterptr this , const default_text_formmaterptr other){
    this->t = other->t;
    this->id = default_text_formatter_ider_next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}
//DefaultTextFormatter& DefaultTextFormatter::operator=(const DefaultTextFormatter& other)
//{
//    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other.id, id);
//    return *this;
//}
default_text_formmaterptr dtf_assignment(default_text_formmaterptr this,default_text_formmaterptr other){
    this->t = other->t;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}
//void DefaultTextFormatter::print(const char* text) const
//{
//    printFunc("[DefaultTextFormatter::print(const char*)]");
//    printf("%s\n", text);
//}
void v_dft_print_cptr(default_text_formmaterptr this,const char* text){
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n",text);
}
//DefaultTextFormatter::~DefaultTextFormatter()
//{
//    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", id);
//}
void dtf_destroy_text(default_text_formmaterptr this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}
//DefaultTextFormatter* generateFormatterArray()
//{
//    return new DefaultTextFormatter[3];
//}
default_text_formmaterptr dft_generateFormatterArray(){
    default_text_formmaterptr new = malloc(sizeof(default_text_formmater)*3);
    for (int i = 0; i < 3; ++i) {
        default_text_formmater tmp;
        init_default_text_formmater(&tmp);
        *(new+i) = tmp;
    }
    return new;
}

////// PrePostFixer Defs ////////////
//PrePostFixer::PrePostFixer(const char* prefix, const char* postfix)
//:   pre(prefix)
//,   post(postfix)
//{
//    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre, post);
//}
void ppf_init_fixer(pre_post_fixerptr this,const char* prefix, const char* postfix){
    init_default_text_formmater(&this->dft);
    this->pre=prefix;
    this->post=postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}
//PrePostFixer::~PrePostFixer()
//{
//    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pre, post);
//}
void ppf_destroy_text(pre_post_fixerptr this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre,this-> post);
    dtf_destroy_text(&this->dft);
}
//void PrePostFixer::print(const char* text) const
//{
//    printFunc("[PrePostFixer::print(const char*)]");
//    printf("%s%s%s\n", pre, text, post);
//}
/*virtual*/void v_ppf_print_cptr(pre_post_fixerptr this,const char* text){
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text,this-> post);
}
/*virtual*/void v_ppf_print_lc(pre_post_fixerptr this,long num , char symbol){
    printf("%-60s | ","[PrePostFixer::print(long, char)]");
    printf("-->\n");
    if (symbol) {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    }
    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }

}
/*virtual*/char ppf_get_default_symbol(pre_post_fixerptr this){
    return '\0';
}

////// PrePostDollarFixer Defs ////////////
//
//PrePostDollarFixer::PrePostDollarFixer(const char* prefix, const char* postfix)
//:   PrePostFixer(prefix, postfix)
//{
//    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//PrePostDollarFixer::PrePostDollarFixer(const PrePostDollarFixer& other)
//:   PrePostFixer(other)
//{
//    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//PrePostDollarFixer::~PrePostDollarFixer()
//{
//    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//void PrePostDollarFixer::print(int num, char symbol) const
//{
//    printFunc("[PrePostDollarFixer::print(int, char)]");
//    printf("-->\n");
//
//    print(long(num), symbol);
//}
//
//void PrePostDollarFixer::print(long num, char symbol) const
//{
//    printFunc("[PrePostDollarFixer::print(long, char)]");
//    printf("-->\n");
//
//    PrePostFixer::print(num, symbol);
//}
//
//void PrePostDollarFixer::print(double num, char symbol) const
//{
//    printFunc("[PrePostDollarFixer::print(double, char)]");
//    printf("%s%c%f%s\n", getPrefix(), symbol, num, getPostfix());
//}
//
//
////// PrePostHashFixer Defs ////////////
//
//PrePostHashFixer::PrePostHashFixer(int prc)
//:   PrePostDollarFixer("===> ", " <===")
//,   precision(prc)
//{
//    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", getPrefix(), getPostfix(), precision);
//
//    print(9999.9999);
//}
//
//PrePostHashFixer::~PrePostHashFixer()
//{
//    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//void PrePostHashFixer::print(int num, char symbol) const
//{
//    printFunc("[PrePostHashFixer::print(int, char)]");
//    printf("-->\n");
//
//    print(double(num), symbol);
//}
//
//void PrePostHashFixer::print(long num, char symbol) const
//{
//    printFunc("[PrePostHashFixer::print(long, char)]");
//    printf("-->\n");
//
//    print(double(num), symbol);
//}
//
//
////// PrePostFloatDollarFixer Defs ////////////
//
//PrePostFloatDollarFixer::PrePostFloatDollarFixer(const char* prefix, const char* postfix)
//:   PrePostDollarFixer(prefix, postfix)
//{
//    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//PrePostFloatDollarFixer::~PrePostFloatDollarFixer()
//{
//    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//void PrePostFloatDollarFixer::print(float num) const
//{
//    printFunc("[PrePostFloatDollarFixer::print(float)]");
//    printf("-->\n");
//
//    print(num, DEFAULT_SYMBOL);
//}
//
//void PrePostFloatDollarFixer::print(float num, char symbol) const
//{
//    printFunc("[PrePostFloatDollarFixer::print(float, char)]");
//
//    printf("%s%c%.2f%s\n", getPrefix(), symbol, num, getPostfix());
//}
//
////// PrePostChecker Defs ////////////
//
//PrePostChecker::PrePostChecker()
//:   PrePostFloatDollarFixer("[[[[ ", " ]]]]")
//{
//    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//PrePostChecker::~PrePostChecker()
//{
//    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
//
//void PrePostChecker::printThisSymbolUsingFunc() const
//{
//    printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");
//
//    printf("Default symbol is %c\n", this->getDefaultSymbol());
//}
//
//void PrePostChecker::printThisSymbolDirectly() const
//{
//    printFunc("[PrePostChecker::printThisSymbolDirectly()]");
//
//    printf("Default symbol is %c\n", this->DEFAULT_SYMBOL);
//}
//
//void PrePostChecker::printDollarSymbolByCastUsingFunc() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
//
//    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->getDefaultSymbol());
//}
//
//void PrePostChecker::printDollarSymbolByScopeUsingFunc() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
//
//    printf("Default symbol is %c\n", this->PrePostDollarFixer::getDefaultSymbol());
//}
//
//void PrePostChecker::printDollarSymbolByCastDirectly() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");
//
//    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL);
//}
//
//void PrePostChecker::printDollarSymbolByScopeDirectly() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");
//
//    printf("Default symbol is %c\n", this->PrePostDollarFixer::DEFAULT_SYMBOL);
//}
//
//
////// Multiplier Defs ////////////
//
//void Multiplier::print(const char* text) const
//{
//    printFunc("[Multiplier::print(const char*)]");
//
//    for (int i = 0; i < times; ++i)
//        printf("%s", text);
//    printf("\n");
//}
//

