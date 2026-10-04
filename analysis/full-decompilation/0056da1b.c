
void __fastcall FUN_0056da1b(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x228) != -2) {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x1a8) + 0x8c))();
    iVar2 = (**(code **)(*piVar1 + 0xac))();
    if ((iVar2 != 0) && (local_8 = *(int *)(iVar2 + 4), local_8 != 0)) {
      if (*(char *)(param_1 + 0x194) == '\0') {
        if (*(int *)(param_1 + 0x228) == -1) {
          return;
        }
        if (*(int *)(*(int *)(param_1 + 0x1a4) + 0x3c) != 0) {
          iVar2 = *(int *)(param_1 + 0x228) + 1;
          *(int *)(param_1 + 0x228) = iVar2;
          if (*(int *)(param_1 + 0x22c) < iVar2) {
            *(undefined4 *)(param_1 + 0x228) = 0;
          }
          FUN_005991b7(*(int *)(param_1 + 0x1a4));
          FUN_005d49b7(*(int *)(param_1 + 0x228) * 0x104 + 0x230 + param_1);
          uVar3 = FUN_005a026f(param_1 + 0x198);
          local_10 = 0x3f800000;
          local_c = 0x3f800000;
          uVar3 = FUN_005a08e3(uVar3,1,&local_c,&local_10,DAT_006e5490);
          *(undefined4 *)(param_1 + 0x1a4) = uVar3;
          FUN_00599214();
          *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x40) = 0;
        }
        *(undefined4 *)(param_1 + 500) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x194) = 0;
        if (*(int *)(param_1 + 0x228) == -1) {
          *(uint *)(param_1 + 0x228) = -(uint)(*(char *)(param_1 + 0x221) != '\0') & 8;
        }
        FUN_005d49b7(*(int *)(param_1 + 0x228) * 0x104 + 0x230 + param_1);
        uVar3 = FUN_005a026f(param_1 + 0x198);
        local_c = 0x3f800000;
        local_10 = 0x3f800000;
        uVar3 = FUN_005a08e3(uVar3,1,&local_10,&local_c,DAT_006e5490);
        *(undefined4 *)(param_1 + 0x1a4) = uVar3;
        FUN_00599214();
        *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x40) = 0;
        *(undefined4 *)(param_1 + 500) = 0;
      }
      FUN_005a0d7d(param_1 + 0x1b4,DAT_006e5490,1);
    }
  }
  return;
}

