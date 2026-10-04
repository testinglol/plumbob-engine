
uint __fastcall FUN_00432249(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  bVar6 = false;
  if (*(short *)(*(int *)(param_1 + 0x118) + 0x14) == 0) {
    bVar6 = *(short *)(param_1 + 0x68) != 0;
    uVar1 = *(ushort *)(param_1 + 0x9c);
  }
  else {
    iVar2 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor
                         ,0);
    if (iVar2 == 0) {
      return 0;
    }
    iVar5 = *(int *)(iVar2 + 400);
    iVar4 = iVar5;
    if (iVar5 == 0) {
      iVar4 = iVar2;
    }
    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x18c)) {
      if ((bVar6) || (*(short *)(iVar4 + 0x68) != 0)) {
        bVar6 = true;
      }
    }
    if (iVar5 == 0) {
      iVar5 = iVar2;
    }
    uVar1 = *(ushort *)(iVar5 + 0x9c);
  }
  uVar3 = (uint)uVar1;
  if (bVar6) {
    uVar3 = (int)(short)uVar1 / 2;
  }
  return uVar3;
}

