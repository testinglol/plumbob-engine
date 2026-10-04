
void FUN_00575f2f(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int *piVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  code *pcStack_124;
  undefined1 *puStack_120;
  code *local_11c;
  
  FUN_00634c24();
  piVar4 = (int *)*extraout_ECX;
  if (((int *)*piVar4 != piVar4) && (*(int **)*piVar4 != piVar4)) {
    local_11c = (code *)0x14;
    puStack_120 = (undefined1 *)0x575f5f;
    uVar3 = FUN_00401742();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    *(undefined4 *)uVar3 = uVar3;
    *(int *)(*(int *)(unaff_EBP + -0x14) + 4) = *(int *)(unaff_EBP + -0x14);
    local_11c = thunk_FUN_0042ed0e;
    puStack_120 = &LAB_00576b23;
    pcStack_124 = (code *)0x40;
    iVar6 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00635e55(unaff_EBP + -0x118,4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    while (local_11c = *(code **)*extraout_ECX, local_11c != (code *)*extraout_ECX) {
      *(code ***)(unaff_EBP + -0x10) = &local_11c;
      *(code ***)(unaff_EBP + -0x10) = &pcStack_124;
      pcStack_124 = local_11c;
      FUN_00602902(&pcStack_124);
      FUN_00576b77();
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (0 < iVar6) {
        piVar4 = (int *)(unaff_EBP + -0x118);
        *(int **)(unaff_EBP + -0x10) = piVar4;
        while (*(int **)*piVar4 != (int *)*piVar4) {
          local_11c = (code *)(unaff_EBP + -0x14);
          puStack_120 = (undefined1 *)0x575fe0;
          FUN_00576c70();
          puVar1 = *(undefined4 **)(unaff_EBP + -0x10);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
          uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
          iVar5 = *(int *)(unaff_EBP + -0x18);
          *(undefined4 *)(unaff_EBP + -0x14) = *puVar1;
          *puVar1 = uVar3;
          if (iVar6 <= iVar5) break;
          piVar4 = *(int **)(unaff_EBP + -0x10);
        }
      }
      uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
      iVar5 = *(int *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x14) =
           *(undefined4 *)(unaff_EBP + -0x118 + *(int *)(unaff_EBP + -0x18) * 4);
      *(undefined4 *)(unaff_EBP + -0x118 + *(int *)(unaff_EBP + -0x18) * 4) = uVar3;
      if (iVar5 == iVar6) {
        iVar6 = iVar6 + 1;
      }
    }
    if (1 < iVar6) {
      iVar5 = unaff_EBP + -0x114;
      *(int *)(unaff_EBP + -0x10) = iVar5;
      *(int *)(unaff_EBP + -0x18) = iVar6 + -1;
      while( true ) {
        local_11c = (code *)(iVar5 + -4);
        puStack_120 = (undefined1 *)0x576043;
        FUN_00576c70();
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
        piVar4 = (int *)(unaff_EBP + -0x18);
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) break;
        iVar5 = *(int *)(unaff_EBP + -0x10);
      }
    }
    iVar5 = *extraout_ECX;
    iVar2 = *(int *)(unaff_EBP + -0x11c + iVar6 * 4);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    local_11c = thunk_FUN_0042ed0e;
    puStack_120 = (undefined1 *)0x40;
    *(int *)(unaff_EBP + -0x11c + iVar6 * 4) = iVar5;
    pcStack_124 = (code *)0x4;
    *extraout_ECX = iVar2;
    FUN_00635f6d(unaff_EBP + -0x118);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    local_11c = (code *)0x576081;
    FUN_0042ed0e();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

