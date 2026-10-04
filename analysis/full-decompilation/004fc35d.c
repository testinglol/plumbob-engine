
/* WARNING: Removing unreachable block (ram,0x004fc438) */
/* WARNING: Removing unreachable block (ram,0x004fc43e) */

undefined4 __thiscall FUN_004fc35d(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  int unaff_retaddr;
  
  if (((*(char *)(param_1 + 0xaf) == '\0') || (*(int *)(DAT_006e486c + 0x24) == 0)) ||
     (iVar2 = FUN_00428886(), iVar2 == 0)) {
    MessageBoxA((HWND)0x0,DAT_006f2700,DAT_006f26e0,0);
    if (*(char *)(param_1 + 0xc4) == '\0') {
      FUN_00637cca(1);
      piVar1 = param_2;
      if (unaff_EBX == 0xc00) {
        if (unaff_retaddr != 0) {
          return 0;
        }
        if (param_2 != (int *)0x0) {
          while (iVar2 = (**(code **)(*piVar1 + 0x20))
                                   (piVar1,&stack0x00000000,&stack0xfffffffc,&param_2,0), -1 < iVar2
                ) {
            (**(code **)(*piVar1 + 0x30))(piVar1,0,0xc00,param_2);
          }
        }
      }
      else if (unaff_EBX == 0xc01) {
        if (unaff_retaddr != 0) {
          return 0;
        }
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
      }
      return 1;
    }
  }
  else {
    iVar2 = MessageBoxA((HWND)0x0,DAT_006f26f0,DAT_006f26e0,4);
    if (iVar2 == 6) {
      FUN_004f277c();
    }
  }
  *(undefined1 *)(param_1 + 0xb0) = 1;
  uVar3 = (**(code **)(*DAT_006fe8bc + 0x24))(0);
  return uVar3;
}

