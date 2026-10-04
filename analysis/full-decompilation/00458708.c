
void FUN_00458708(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  iVar3 = 0;
  if ((DAT_006e4f18 == 0) &&
     ((((uint)(int)*(short *)(*extraout_ECX + 0x60e) >> 1 & 1) != 0 ||
      (((uint)(int)*(short *)(*extraout_ECX + 0x60e) >> 2 & 1) != 0)))) {
    iVar1 = FUN_0045741b();
    if (iVar1 != 0x7c4) goto LAB_00458860;
  }
  iVar1 = FUN_00457e1c();
  if (iVar1 != 0) {
    DAT_006e50ac = *(undefined4 *)(unaff_EBP + 8);
    iVar2 = *(int *)(iVar1 + 4);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (0 < iVar2) {
      do {
        if ((iVar3 < 0) || (*(int *)(iVar1 + 4) <= iVar3)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + iVar3 * 4);
        }
        FUN_0041f010(*extraout_ECX,extraout_ECX[1],*(undefined4 *)(iVar2 + 0x18),0x32);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_00458871(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x98);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(unaff_EBP + -0x10));
    }
    iVar3 = FUN_0041f101();
    if ((iVar3 != 0) && ((*(uint *)(iVar3 + 0x14) >> 1 & 1) != 0)) {
      iVar3 = FUN_006359f2(extraout_ECX[1],0,&cXObject::RTTI_Type_Descriptor,
                           &cXPerson::RTTI_Type_Descriptor,0);
      if ((iVar3 != 0) && (iVar3 != *extraout_ECX)) {
        FUN_0041ee9b(iVar3,*extraout_ECX);
        iVar3 = *extraout_ECX;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        *(undefined2 *)(unaff_EBP + -0x3c) = *(undefined2 *)(iVar3 + 0xf0);
        FUN_0041f0db(unaff_EBP + -0x40);
        FUN_00458871(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x54);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
    }
    DAT_006e50e0 = 0;
  }
LAB_00458860:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

