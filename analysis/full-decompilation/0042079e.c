
int FUN_0042079e(int param_1,int param_2)

{
  int iVar1;
  int *local_c;
  
  FUN_0040165b(&DAT_006e48e8);
  while( true ) {
    if (local_c == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *local_c;
    }
    if (iVar1 == 0) break;
    if ((*(int *)(iVar1 + 0x10) == param_1) && (*(short *)(iVar1 + 0xc) == param_2)) {
      return iVar1;
    }
    FUN_00420c2e();
  }
  return 0;
}

