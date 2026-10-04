
int __thiscall FUN_004a3a2b(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    iVar2 = FUN_004b5717();
    FUN_004a3ace(*(undefined4 *)(iVar2 + 0x60));
  }
  iVar2 = param_1[2];
  iVar1 = ((param_1[1] / iVar2 + -1) / 2) * 2;
  return ((iVar1 - param_3) + param_2) * (iVar2 / 2) +
         (iVar1 + param_2 + param_3) * (iVar2 / 4) * param_1[1] + *param_1;
}

