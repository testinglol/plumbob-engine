
int __thiscall FUN_004561c2(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = 0;
  }
  else {
    iVar1 = (param_2 - (param_1[1] - *param_1 >> 2)) + 1;
    if (0 < iVar1) {
      param_2 = 0;
      FUN_004564f0(param_1[1],iVar1,&param_2);
    }
    iVar2 = *param_1 + iVar2 * 4;
  }
  return iVar2;
}

