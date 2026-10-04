
int __thiscall FUN_00466583(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_c;
  
  FUN_0040165b(param_1 + 0x10);
  FUN_0040165b();
  while( true ) {
    if (local_c == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *local_c;
    }
    if (iVar1 == 0) goto LAB_004665d4;
    if (local_c == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *local_c;
    }
    if (*(int *)(iVar1 + 4) == param_2) break;
    FUN_00420c2e();
  }
  if (local_c == (int *)0x0) {
LAB_004665d4:
    iVar1 = 0;
  }
  else {
    iVar1 = *local_c;
  }
  return iVar1;
}

