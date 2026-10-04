
int __thiscall FUN_00416e18(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00418722(param_1,param_2,0x4e414d45,1,0);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0xc) = 0;
      iVar2 = (**(code **)(*param_2 + 0x38))(0x4e414d45,0,FUN_00416e17);
      if (iVar2 != 0) {
        (**(code **)(*param_2 + 0x80))(iVar2);
        FUN_00401f6f();
      }
      FUN_004659fc(0);
    }
  }
  return iVar1;
}

