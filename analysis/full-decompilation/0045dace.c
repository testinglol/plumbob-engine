
undefined4 FUN_0045dace(void)

{
  short sVar1;
  short sVar2;
  byte *pbVar3;
  int *piVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int extraout_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  pbVar3 = *(byte **)(unaff_EBP + 0xc);
  if (pbVar3[1] != 1) {
    FUN_0046f824(unaff_EBP + -0x130,0,0x100);
    *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_00666524;
    FUN_0046f824(unaff_EBP + -0x23c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x248) = &PTR_FUN_00666524;
    pbVar3 = *(byte **)(unaff_EBP + 0xc);
    if (pbVar3[1] == 0) {
      iVar7 = FUN_00401f73();
      uVar10 = extraout_var_00;
    }
    else {
      if (pbVar3[1] != 2) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0x2f;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
      }
      iVar7 = FUN_00401f6f();
      uVar10 = extraout_var;
    }
    if (*(short *)(unaff_EBP + -0x134) == 0) {
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0x2f;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
      }
      FUN_00465b21(unaff_EBP + -0x13c,iVar7,0x130,CONCAT22(uVar10,(ushort)*pbVar3) + 1);
      if (*(short *)(unaff_EBP + -0x134) == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0x30;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
      }
    }
    FUN_0046f9f6();
    if ((pbVar3[2] & 1) == 0) {
      uVar8 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x244));
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar9 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x138));
      iVar7 = **(int **)(extraout_ECX + 0xadc);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      (**(code **)(iVar7 + 0xd8))(uVar9,uVar8);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    else {
      uVar8 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x138));
      piVar4 = *(int **)(extraout_ECX + 0xadc);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*piVar4 + 0xdc))(uVar8);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    FUN_005b8770();
    goto LAB_0045dcec;
  }
  if ((pbVar3[2] & 1) != 0) goto LAB_0045dcec;
  if (*pbVar3 < 8) {
    *(undefined2 *)(extraout_ECX + 0x5b6) = 0;
  }
  else {
    sVar1 = *(short *)(extraout_ECX + 0x5b6);
    sVar2 = *(short *)(extraout_ECX + 0x600);
    if ((ushort)*pbVar3 == *(ushort *)(extraout_ECX + 0x59c)) {
      if ((sVar2 == 0) || (0x11 < sVar2)) {
        do {
          uVar6 = FUN_0046f556();
          uVar6 = uVar6 % 10;
        } while (uVar6 == (int)sVar1);
LAB_0045db62:
        uVar5 = (ushort)uVar6;
      }
      else {
        uVar5 = (ushort)((int)sVar1 == 0);
      }
    }
    else {
      if ((sVar2 == 0) || (0x11 < sVar2)) {
        uVar6 = FUN_0046f556();
        uVar6 = uVar6 % 10;
        goto LAB_0045db62;
      }
      uVar5 = FUN_0046f556();
      uVar5 = uVar5 & 1;
    }
    *(ushort *)(extraout_ECX + 0x5b6) = uVar5;
  }
  *(ushort *)(extraout_ECX + 0x59c) = (ushort)*pbVar3;
LAB_0045dcec:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

