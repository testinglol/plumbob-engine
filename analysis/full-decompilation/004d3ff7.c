
void FUN_004d3ff7(void)

{
  int *piVar1;
  char cVar2;
  undefined4 unaff_retaddr;
  
  piVar1 = *(int **)(*(int *)(DAT_006f2a08 + 0x84) + 0x1164);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x8c))(1);
    if (cVar2 != '\0') {
      FUN_004d5e20(unaff_retaddr);
    }
  }
  return;
}

