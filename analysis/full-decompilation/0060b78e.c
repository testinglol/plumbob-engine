
int __thiscall FUN_0060b78e(int *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  pcVar1 = param_2 + param_3 + -1;
  if (param_3 != 0) {
    for (; param_2 <= pcVar1; param_2 = param_2 + 1) {
      cVar2 = (**(code **)(*param_1 + 0x3c))((int)*param_2);
      if (cVar2 == '\0') break;
      iVar3 = (**(code **)(*param_1 + 0x5c))((int)*param_2);
      local_8 = local_8 + iVar3;
    }
  }
  return param_1[0xd] + local_8;
}

