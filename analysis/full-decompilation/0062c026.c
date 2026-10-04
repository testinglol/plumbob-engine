
undefined4 __thiscall FUN_0062c026(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0) {
    if ((char)param_1[0x924] == '\x03') {
      uVar2 = FUN_0062f56b(param_2);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

