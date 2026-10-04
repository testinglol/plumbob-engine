
void __fastcall FUN_0042071f(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_c;
  
  *param_1 = &PTR_FUN_006669f4;
  FUN_0040165b();
  do {
    FUN_0040165b();
    while( true ) {
      if (local_c == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *local_c;
      }
      if (iVar2 == 0) {
        DestroyMenu((HMENU)param_1[1]);
        FUN_004665e6(param_1);
        return;
      }
      if (local_c == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *local_c;
      }
      if (*(undefined4 **)(iVar2 + 8) == param_1) break;
      FUN_00420c2e();
    }
    if (local_c == (int *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = (undefined4 *)*local_c;
    }
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  } while( true );
}

