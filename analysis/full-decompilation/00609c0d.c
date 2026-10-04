
int __thiscall FUN_00609c0d(int *param_1,char *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = param_2;
  param_2 = (char *)0x0;
  for (; ((param_3 != 0 && (uVar1 = FUN_00609af3(pcVar3), uVar1 != 0)) && (uVar1 <= param_3));
      param_3 = param_3 - uVar1) {
    iVar2 = (**(code **)(*param_1 + 0x5c))((int)*pcVar3);
    param_2 = (char *)((int)param_2 + iVar2);
    pcVar3 = pcVar3 + uVar1;
  }
  return (int)param_2;
}

