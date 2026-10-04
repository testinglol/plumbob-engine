
int __fastcall FUN_00435244(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  
  if (*(short *)(*(int *)(param_1 + 0x118) + 0x12) != 2) {
    sVar1 = *(short *)(*(int *)(param_1 + 0x118) + 0x86);
    if (sVar1 != 0) {
      return (int)sVar1;
    }
    return 0x10;
  }
  iVar3 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
  if (iVar3 != 0) {
    cVar2 = FUN_00435294();
    if (cVar2 != '\0') {
      return 0;
    }
  }
  return DAT_006c296c;
}

