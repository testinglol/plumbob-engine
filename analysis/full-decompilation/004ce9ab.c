
void __fastcall FUN_004ce9ab(int param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((*(uint *)(param_1 + 0xc) & 0x1000000) != 0) {
    *(bool *)(param_1 + 100) =
         (*(int *)(*(int *)(*DAT_006e486c + 0x14) + 0x3c) -
          *(int *)(*(int *)(*DAT_006e486c + 0x14) + 0x38) & 0xfffffffcU) != 0;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x2000) != 0) {
    sVar1 = *(short *)(DAT_006e486c[7] + 0x10);
    sVar2 = *(short *)(DAT_006e486c[7] + 0x1a);
    piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
    (**(code **)(*piVar4 + 0x80))(param_1 + 0x18,(int)sVar1,(int)sVar2,1,1);
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x2000;
  }
  if ((*(byte *)(param_1 + 0xd) & 0x40) != 0) {
    uVar5 = FUN_0046d9e5();
    FUN_004cee90(uVar5);
  }
  if ((*(uint *)(param_1 + 0xc) & 0x1000) != 0) {
    uVar5 = (**(code **)(**(int **)(param_1 + 0x1f0) + 0x14))();
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x1000;
    *(undefined4 *)(param_1 + 0x34) = uVar5;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x800) != 0) {
    uVar5 = (**(code **)(**(int **)(param_1 + 0x1f0) + 0x18))();
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x800;
    *(undefined4 *)(param_1 + 0x38) = uVar5;
    FUN_004cefd8();
  }
  if ((*(uint *)(param_1 + 0xc) & 0x100) != 0) {
    iVar6 = (**(code **)(**(int **)(param_1 + 0x1f0) + 0x38))();
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x100;
    *(int *)(param_1 + 0x3c) = iVar6;
    FUN_004cefd8();
    FUN_0042004f();
  }
  if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
    uVar5 = FUN_0046d8a7();
    FUN_004cf024(uVar5);
  }
  if ((*(byte *)(param_1 + 0xe) & 0x80) != 0) {
    uVar5 = FUN_0046d982();
    FUN_004cefe5(uVar5);
  }
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    cVar3 = FUN_004a838e();
    if (cVar3 == '\0') {
      cVar3 = FUN_005e685e();
      if (cVar3 == '\0') {
        cVar3 = FUN_004b16ac();
        if (cVar3 == '\0') {
          uVar5 = 1;
        }
        else {
          uVar5 = 8;
        }
      }
      else {
        uVar5 = 4;
      }
    }
    else {
      uVar5 = 2;
    }
    FUN_004cf0ab(uVar5,1);
    FUN_0042004f();
  }
  if ((*(byte *)(param_1 + 0xc) & 8) != 0) {
    uVar5 = FUN_004e99a9();
    *(undefined4 *)(param_1 + 0x1ec) = uVar5;
  }
  return;
}

