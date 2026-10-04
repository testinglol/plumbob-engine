
int FUN_00517c78(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar9;
  
  FUN_00634c24();
  iVar8 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  if (*(short *)(*(int *)(iVar8 + 0x1c) + 0x50) == 1) {
    pvVar4 = operator_new(0x124);
    *(void **)(unaff_EBP + -0x14) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0050d78c(CONCAT22((short)((uint)*(int *)(DAT_006e486c + 0x1c) >> 0x10),
                                            *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x24)),
                                   *(undefined4 *)(unaff_EBP + 8));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if ((piVar5 != (int *)0x0) && (cVar3 = (**(code **)(*piVar5 + 0xc))(), cVar3 != '\0')) {
      piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      iVar7 = (**(code **)(*piVar6 + 8))();
      iVar8 = *(int *)(iVar7 + 0x7c);
      iVar1 = *(int *)(iVar7 + 0x80);
      iVar2 = *(int *)(iVar7 + 0x84);
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar7 + 0x88);
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) - iVar1;
      FUN_004cb21d((((piVar5[0x1f] - piVar5[0x21]) - iVar8) + iVar2) / 2,
                   ((piVar5[0x20] - piVar5[0x22]) + *(int *)(unaff_EBP + -0x18)) / 2);
      piVar5[0x12] = *(int *)(unaff_EBP + -0x10);
      FUN_004d3f37(1);
      uVar9 = 0;
      piVar6 = piVar5;
      (**(code **)(*DAT_006fe8bc + 0x18))(0,piVar5);
      iVar8 = FUN_005daa44(uVar9,piVar6);
      FUN_004d3f37(0);
      FUN_005da4c7(piVar5);
      FUN_005db1e2();
      if (iVar8 == 3) {
        iVar8 = 1;
      }
      else {
        iVar8 = (iVar8 != 1) - 1;
      }
      goto LAB_00517dcd;
    }
  }
  iVar8 = -2;
LAB_00517dcd:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar8;
}

