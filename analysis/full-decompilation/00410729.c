
undefined1 FUN_00410729(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  undefined2 extraout_var;
  int extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x10c) != -1) {
    if (*(int *)(extraout_ECX + 0x148) != 0) {
      FUN_004ede5e();
    }
    uVar1 = *(undefined2 *)(extraout_ECX + 0x10c);
    *(int *)(unaff_EBP + -0x20) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x46414d49;
    *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_0066665c;
    piVar2 = *(int **)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar3 = FUN_00464eab(unaff_EBP + -0x24,9,piVar2,uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00465055();
    if (iVar3 == 0) {
      FUN_004706f0();
      uVar1 = *(undefined2 *)(extraout_ECX + 0x10c);
      uVar4 = 1;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_0047034e(piVar2,CONCAT22(extraout_var,uVar1),0x46414d73,0,0xffffffff);
      FUN_0047132c(1,*(undefined4 *)(extraout_ECX + 4),0xffffffff);
      iVar3 = FUN_0047078e();
      if (iVar3 == 0) {
        if (*(int *)(extraout_ECX + 0x140) == 0) {
          if (*(int *)(extraout_ECX + 0x144) != 0) {
            uVar1 = *(undefined2 *)(extraout_ECX + 0x10c);
            *(int *)(unaff_EBP + -0x14) = *(int *)(extraout_ECX + 0x144);
            *(undefined4 *)(unaff_EBP + -0x10) = 0x46414d68;
            *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_0066664c;
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_00464eab(unaff_EBP + -0x18,1,piVar2,uVar1);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_00465055();
          }
        }
        else {
          FUN_0046f824(unaff_EBP + -0x68,0,0x40);
          *(undefined ***)(unaff_EBP + -0x74) = &PTR_FUN_0066651c;
          FUN_0046f847(&DAT_006de560,0xffffffff);
          (**(code **)(*piVar2 + 0x74))
                    (*(undefined4 *)(extraout_ECX + 0x140),0x46414d68,
                     CONCAT22((short)((uint)(unaff_EBP + -0x74) >> 0x10),
                              *(undefined2 *)(extraout_ECX + 0x10c)),unaff_EBP + -0x74,1);
          (**(code **)(*piVar2 + 0x7c))(*(undefined4 *)(extraout_ECX + 0x140));
          (**(code **)(*piVar2 + 100))(*(undefined4 *)(extraout_ECX + 0x140));
        }
      }
      else {
        uVar4 = 0;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004712d0();
      goto LAB_004108b3;
    }
  }
  uVar4 = 0;
LAB_004108b3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

