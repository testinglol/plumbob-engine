
void FUN_004d40b6(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0051cebb();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x268))(0xffffffff);
  }
  piVar1 = (int *)FUN_0051cecc();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x268))(0xffffffff);
  }
  return;
}

