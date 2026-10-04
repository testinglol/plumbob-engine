
void __thiscall FUN_0056815a(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iStack_18;
  
  iVar4 = param_2[0x17];
  iVar6 = param_3 * 4;
  iVar3 = *(int *)(*(int *)(param_1 + 0x36c + *(int *)(param_2[0xf] + iVar6) * 4) + 0x1c) + 4;
  if (param_3 < 1) {
    iVar1 = ((int *)*param_2)[param_2[0x16] + -1];
    iVar2 = *(int *)*param_2;
    if ((iVar2 <= iVar1 - iVar3) || (iVar1 < iVar2)) {
      iVar3 = _rand();
      if ((iVar3 % 10 == 1) && (iVar4 < *(int *)(param_2[9] + iVar6))) goto LAB_00568219;
      iVar4 = _rand();
      if (iVar4 % 10 != 1) goto LAB_00568247;
      piVar5 = (int *)param_2[6];
      goto LAB_0056823a;
    }
    piVar5 = (int *)param_2[6];
LAB_0056821e:
    if (*piVar5 < 1) goto LAB_00568247;
    iVar4 = *piVar5 + -1;
  }
  else {
    if (*(int *)(param_2[0xc] + iVar6) == 1) {
      iVar3 = _rand();
      if ((iVar3 % 10 == 1) && (iVar4 < *(int *)(param_2[9] + iVar6))) {
LAB_00568219:
        piVar5 = (int *)(param_2[6] + iVar6);
        goto LAB_0056821e;
      }
      iVar4 = _rand();
      iStack_18 = 0x28;
    }
    else {
      if (((int *)(*param_2 + iVar6))[-1] - iVar3 < *(int *)(*param_2 + iVar6)) goto LAB_00568219;
      iVar4 = _rand();
      iStack_18 = 10;
    }
    if (iVar4 % iStack_18 != 1) goto LAB_00568247;
    piVar5 = (int *)(param_2[6] + iVar6);
LAB_0056823a:
    if (*(int *)(param_1 + 0x364) <= *piVar5) goto LAB_00568247;
    iVar4 = *piVar5 + 1;
  }
  *piVar5 = iVar4;
LAB_00568247:
  *(int *)(*param_2 + iVar6) = *(int *)(*param_2 + iVar6) + *(int *)(iVar6 + param_2[6]) * 3;
  *(int *)(param_2[3] + iVar6) = *(int *)(param_2[3] + iVar6) - *(int *)(iVar6 + param_2[6]);
  return;
}

