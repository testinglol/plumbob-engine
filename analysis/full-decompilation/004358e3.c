
undefined4 __fastcall FUN_004358e3(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(byte *)(param_1 + 100) & 0xf) == 0) {
    if (*(short *)(*(int *)(param_1 + 0x118) + 0x14) != 0) {
      iVar2 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,
                           &cXMTObject::RTTI_Type_Descriptor,0);
      iVar1 = *(int *)(iVar2 + 400);
      iVar4 = iVar1;
      if (iVar1 == 0) {
        iVar4 = iVar2;
      }
      for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x18c)) {
        if ((*(byte *)(iVar4 + 100) & 0xf) != 0) goto LAB_0043595f;
        iVar5 = iVar1;
        if (iVar1 == 0) {
          iVar5 = iVar2;
        }
        if (iVar5 != 0) {
          do {
            if (((*(ushort *)(iVar4 + 0x9e) & 0x800) != 0) && ((*(byte *)(iVar5 + 0x9f) & 8) == 0))
            goto LAB_0043595f;
            iVar5 = *(int *)(iVar5 + 0x18c);
          } while (iVar5 != 0);
        }
      }
    }
    uVar3 = 0;
  }
  else {
LAB_0043595f:
    uVar3 = 1;
  }
  return uVar3;
}

