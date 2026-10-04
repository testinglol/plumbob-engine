
void __thiscall FUN_005409be(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 == 0) {
    iVar2 = 0;
    param_2 = 2;
  }
  else {
    iVar2 = param_2 + -1;
  }
  if (iVar2 < param_2) {
    param_2 = param_2 - iVar2;
    piVar3 = (int *)(param_1 + 0x10 + iVar2 * 4);
    do {
      piVar1 = (int *)piVar3[-2];
      if (1 < (uint)(piVar1[1] - *piVar1 >> 2)) {
        FUN_005414fb(*piVar1,piVar1[1],&LAB_00540a2f);
      }
      piVar1 = (int *)*piVar3;
      if (1 < (uint)(piVar1[1] - *piVar1 >> 2)) {
        FUN_0054153e(*piVar1,piVar1[1],&LAB_00540a42);
      }
      piVar3 = piVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

