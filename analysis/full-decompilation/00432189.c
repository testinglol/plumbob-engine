
void __thiscall FUN_00432189(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  param_2 = param_2 & 0x1f;
  if (*(short *)(*(int *)(param_1 + 0x118) + 0x14) == 0) {
    if ((*(uint *)(param_1 + 0x114) & 0x1f) == param_2) {
      return;
    }
    *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) & 0xffffffe0 | param_2;
  }
  else {
    iVar2 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor
                         ,0);
    cVar1 = FUN_00423481();
    if (cVar1 == '\0') {
      iVar3 = *(int *)(iVar2 + 400);
      if (*(int *)(iVar2 + 400) != 0) goto LAB_004321f4;
      while (iVar3 = iVar2, iVar2 != 0) {
LAB_004321f4:
        if ((*(uint *)(iVar3 + 0x114) & 0x1f) != param_2) {
          *(uint *)(iVar3 + 0x114) = *(uint *)(iVar3 + 0x114) & 0xffffffe0 | param_2;
          FUN_004341a6(0);
        }
        iVar2 = *(int *)(iVar3 + 0x18c);
      }
      return;
    }
    if ((*(uint *)(param_1 + 0x114) & 0x1f) == param_2) {
      return;
    }
    *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) & 0xffffffe0 | param_2;
  }
  FUN_004341a6(0);
  return;
}

