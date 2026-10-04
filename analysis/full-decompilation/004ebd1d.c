
undefined4 FUN_004ebd1d(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar8;
  
  FUN_00634c24();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 == '\0') {
    thunk_FUN_005dbf32();
    if (DAT_006f26a8 == 0) {
      FUN_005a5631(0x139c,&DAT_006f26a8,4);
    }
    extraout_ECX[0x6b] = *(int *)(DAT_006f26a8 + 0x20) / 3;
    (**(code **)(*extraout_ECX + 0x19c))(DAT_006f26a8,1,3);
    extraout_ECX[0x3d] = 1;
    extraout_ECX[0x3e] = 1;
    FUN_005e4a66(1);
    piVar8 = extraout_ECX + 0x65;
    *(undefined4 *)(unaff_EBP + -0x10) = 3;
    do {
      if (*piVar8 == 0) {
        pvVar6 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar6;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar6 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *piVar8 = iVar7;
        if (iVar7 != 0) {
          FUN_005e4a66(1);
          (**(code **)(*(int *)*piVar8 + 0x60))(0,0,0x2d,extraout_ECX[0x6b]);
          iVar7 = extraout_ECX[0x6b];
          iVar2 = *piVar8;
          *(undefined4 *)(iVar2 + 0x144) = 0;
          *(int *)(iVar2 + 0x148) = (iVar7 + -0x2d) / 2 + -5;
          uVar5 = FUN_005d4956(s_ingredient___006c9ec0);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          FUN_005dd9c8(uVar5);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          (**(code **)(*extraout_ECX + 0x20))(*piVar8);
        }
      }
      piVar8 = piVar8 + 1;
      piVar1 = (int *)(unaff_EBP + -0x10);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    iVar3 = DAT_006f26a4;
    iVar2 = extraout_ECX[0x6b];
    iVar7 = DAT_006f26a0 + 0xcc;
    *(int *)(unaff_EBP + -0x44) = DAT_006f26a0;
    *(undefined4 *)(unaff_EBP + -0x3c) = 0x44;
    *(undefined4 *)(unaff_EBP + -0x38) = 0x44;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0x44;
    *(undefined4 *)(unaff_EBP + -0x28) = 0x44;
    *(int *)(unaff_EBP + -0x40) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x34) = iVar7;
    *(int *)(unaff_EBP + -0x30) = iVar2 + iVar3;
    FUN_004ebf01(extraout_ECX + 0x65,3);
    FUN_00511f67(3,s_MagicMasterSpells_iff_006c9ea8,extraout_ECX + 0x70);
    FUN_00511f67(4,s_MagicMasterSpells_iff_006c9ea8,extraout_ECX + 0x8b);
    FUN_00511f67(5,s_MagicMasterSpells_iff_006c9ea8,extraout_ECX + 0xa6);
    FUN_00511f67(7,s_MagicMasterSpells_iff_006c9ea8,extraout_ECX + 0xc1);
    uVar5 = 1;
  }
  else {
    uVar5 = thunk_FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

