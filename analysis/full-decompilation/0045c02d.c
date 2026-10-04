
undefined4 FUN_0045c02d(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = FUN_0045c06f(param_1 + 0xa48);
  if (cVar1 == '\0') {
    iVar3 = *(int *)(param_1 + 0xa44) - *(int *)(param_1 + 0xa40);
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) {
        return 0;
      }
      uVar2 = FUN_0045d8f7(iVar3);
      cVar1 = FUN_0045c06f(uVar2);
    } while (cVar1 == '\0');
  }
  return 1;
}

