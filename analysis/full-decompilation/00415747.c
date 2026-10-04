
void __thiscall FUN_00415747(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  for (iVar1 = *param_1; iVar1 != param_1[1]; iVar1 = iVar1 + 0xc) {
    *(undefined1 *)(iVar1 + 8) = 0;
  }
  do {
    for (piVar2 = (int *)*param_1; piVar2 != (int *)param_1[1]; piVar2 = piVar2 + 3) {
      if ((*piVar2 == param_2) && ((char)piVar2[2] == '\0')) {
        param_2 = piVar2[1];
        *(undefined1 *)(piVar2 + 2) = 1;
        break;
      }
    }
    if (piVar2 == (int *)param_1[1]) {
      return;
    }
  } while( true );
}

