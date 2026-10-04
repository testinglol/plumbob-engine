
int __fastcall FUN_00463804(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1;
  do {
    if (*(short *)(*(int *)(param_1 + 0x118) + 0x8a) == 1) {
      iVar1 = *(int *)(iVar4 + 400);
      iVar3 = iVar1;
      if (iVar1 == 0) {
        iVar3 = iVar4;
      }
      while ((iVar3 == iVar4 ||
             (*(short *)(*(int *)(iVar3 + 0x118) + 0x10) !=
              *(short *)(*(int *)(iVar4 + 0x118) + 0x10)))) {
        iVar3 = *(int *)(iVar3 + 0x18c);
        iVar5 = iVar1;
        if (iVar1 == 0) {
          iVar5 = iVar4;
        }
        if (iVar3 == iVar5) {
          return 0;
        }
        if (iVar3 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar3 = *(int *)(iVar4 + 0x18c);
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar4 + 400);
      }
    }
    iVar4 = FUN_006359f2(iVar3,0,&cXMTObject::RTTI_Type_Descriptor,&cXPortal::RTTI_Type_Descriptor,0
                        );
    if (iVar4 == param_1) {
      return 0;
    }
    FUN_00457da4();
    sVar2 = FUN_004561a0(0xf);
  } while (sVar2 == 0);
  return iVar4;
}

