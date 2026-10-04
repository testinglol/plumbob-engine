
int __fastcall FUN_0043532b(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1;
  if ((*(short *)(*(int *)(param_1 + 0x118) + 0x14) != 0) &&
     (sVar1 = *(short *)(*(int *)(param_1 + 0x118) + 0x10), 0 < sVar1)) {
    iVar2 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor
                         ,0);
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 400) != 0) {
        iVar2 = *(int *)(iVar2 + 400);
      }
      while ((iVar3 = param_1, iVar2 != 0 &&
             (iVar3 = iVar2, *(short *)(*(int *)(iVar2 + 0x118) + 0x10) != -sVar1))) {
        iVar2 = *(int *)(iVar2 + 0x18c);
      }
    }
  }
  return iVar3;
}

