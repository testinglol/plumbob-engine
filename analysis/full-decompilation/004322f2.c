
void __fastcall FUN_004322f2(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  FUN_00432396();
  iVar1 = *(int *)(param_1 + 0x118);
  if (*(short *)(iVar1 + 0x14) != 0) {
    iVar1 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor
                         ,0);
    if (iVar1 == 0) {
      return;
    }
    iVar3 = *(int *)(iVar1 + 400);
    if (*(int *)(iVar1 + 400) == 0) {
      iVar3 = iVar1;
    }
    if (iVar3 != iVar1) {
      return;
    }
    iVar1 = FUN_0043aeef(*(undefined4 *)(param_1 + 0x11c));
    if (iVar1 == 0) {
      return;
    }
    iVar1 = *(int *)(iVar1 + 0x60);
  }
  if (*(short *)(iVar1 + 0x4a) == 0) {
    if ((*(short *)(param_1 + 0x9c) != *(short *)(iVar1 + 0x24)) ||
       (sVar2 = *(short *)(iVar1 + 0x46), sVar2 == 0)) {
      sVar2 = *(short *)(iVar1 + 0x48);
    }
    sVar2 = *(short *)(param_1 + 0x9c) - sVar2;
    if (sVar2 < *(short *)(iVar1 + 0x4c)) {
      sVar2 = *(short *)(iVar1 + 0x4c);
    }
    *(short *)(param_1 + 0x9c) = sVar2;
  }
  return;
}

