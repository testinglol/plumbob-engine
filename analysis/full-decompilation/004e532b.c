
void FUN_004e532b(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (7 < (int)(param_2 - param_1 & 0xfffffffcU)) {
    iVar1 = param_2 - param_1 >> 2;
    iVar2 = (iVar1 + -2) / 2;
    puVar3 = (undefined4 *)(param_1 + iVar2 * 4);
    while( true ) {
      FUN_004e5372(param_1,iVar2,iVar1,*puVar3);
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    }
  }
  return;
}

