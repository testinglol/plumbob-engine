
int __thiscall FUN_004015a1(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_c;
  
  FUN_0040165b(param_1);
  while( true ) {
    if (local_c == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *local_c;
    }
    if (iVar1 == 0) goto LAB_004015de;
    if (param_2 == 0) break;
    FUN_00420c2e();
    param_2 = param_2 + -1;
  }
  if (local_c == (int *)0x0) {
LAB_004015de:
    iVar1 = 0;
  }
  else {
    iVar1 = *local_c;
  }
  return iVar1;
}

