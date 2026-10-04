
undefined4 FUN_00440914(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = FUN_0043acf5(param_1);
  piVar2 = (int *)FUN_00445897(uVar1);
  if (piVar2[1] - *piVar2 >> 2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)*piVar2;
  }
  return uVar1;
}

