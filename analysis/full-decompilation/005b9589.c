
void FUN_005b9589(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = param_1[1];
  iVar2 = *param_1;
  if (0 < iVar1 - iVar2) {
    do {
      if (*(char *)(*param_1 + iVar4) == 0x2f) {
        uVar3 = 0x5c;
      }
      else {
        uVar3 = FUN_0063813a((int)*(char *)(*param_1 + iVar4));
      }
      *(undefined1 *)(*param_1 + iVar4) = uVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1 - iVar2);
  }
  return;
}

