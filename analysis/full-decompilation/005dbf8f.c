
int __thiscall FUN_005dbf8f(int *param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if ((char)param_3 == '\0') {
    cVar1 = (param_2 & param_1[0x27]) != 0;
    param_1[0x27] = ~param_2 & param_1[0x27];
  }
  else {
    cVar1 = '\x01' - ((param_1[0x27] & param_2) != 0);
    param_1[0x27] = param_1[0x27] | param_2;
  }
  if (cVar1 == '\0') goto LAB_005dc054;
  if (param_2 == 1) {
    cVar1 = (**(code **)(*param_1 + 0x8c))(0x80);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x174))(param_3,0);
    }
    (**(code **)(*param_1 + 0x168))();
    iVar3 = (**(code **)(*param_1 + 0x18))();
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*param_1 + 0x18))();
      (**(code **)(*piVar4 + 0x168))();
    }
    goto LAB_005dc054;
  }
  if (param_2 != 0x80) goto LAB_005dc054;
  if ((char)param_3 == '\0') {
LAB_005dbffb:
    uVar2 = 0;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x8c))(1);
    if (cVar1 == '\0') goto LAB_005dbffb;
    uVar2 = 1;
  }
  (**(code **)(*param_1 + 0x174))(uVar2,0);
LAB_005dc054:
  return param_1[0x27];
}

