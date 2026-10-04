
void __thiscall FUN_004704a5(int param_1,size_t param_2,char *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  
  piVar1 = (int *)(param_1 + 0x60);
  if ((param_2 <= (*(int *)(param_1 + 100) - *(int *)(param_1 + 0x60) >> 2) + 1U) &&
     (0 < (int)param_2)) {
    if (param_2 == (*(int *)(param_1 + 100) - *piVar1 >> 2) + 1U) {
      FUN_00471697();
    }
    iVar3 = param_2 * 4;
    iVar2 = *(int *)(iVar3 + -4 + *piVar1);
    if (iVar2 != 0) {
      FUN_006321f0(iVar2);
    }
    param_2 = 0;
    if (param_3 != (char *)0x0) {
      param_2 = _strlen(param_3);
    }
    pcVar4 = operator_new(param_2 + 1);
    pcVar6 = pcVar4;
    for (uVar5 = param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar5 = param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar6 = *param_3;
      param_3 = param_3 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcVar4[param_2] = '\0';
    *(char **)(iVar3 + -4 + *piVar1) = pcVar4;
  }
  return;
}

