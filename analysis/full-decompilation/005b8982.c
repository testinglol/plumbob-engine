
void __fastcall FUN_005b8982(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = param_1[1] - *param_1;
  if (iVar1 != 0) {
    iVar3 = 0;
    for (pcVar2 = (char *)(*param_1 + -1 + iVar1); *pcVar2 == ' '; pcVar2 = pcVar2 + -1) {
      iVar3 = iVar3 + 1;
    }
    if (iVar3 != 0) {
      FUN_00406466(iVar1 - iVar3,DAT_00666580);
    }
  }
  return;
}

