
undefined4 __thiscall FUN_0060b7da(int *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  pcVar1 = param_2;
  pcVar4 = param_2 + param_3 + -1;
  if (param_3 == 0) {
    uVar3 = 0;
  }
  else {
    param_2 = (char *)param_3;
    for (; pcVar1 <= pcVar4; pcVar4 = pcVar4 + -1) {
      cVar2 = (**(code **)(*param_1 + 0x38))((int)*pcVar4);
      if (cVar2 == '\0') {
        cVar2 = (**(code **)(*param_1 + 0x3c))((int)*pcVar4);
        if (cVar2 != '\0') break;
      }
      param_2 = (char *)((int)param_2 + -1);
    }
    uVar3 = (**(code **)(*param_1 + 0x68))(pcVar1,param_2);
  }
  return uVar3;
}

