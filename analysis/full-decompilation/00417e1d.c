
void __thiscall
FUN_00417e1d(int *param_1,undefined4 param_2,short param_3,undefined4 *param_4,char param_5)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_58 [64];
  undefined1 local_18 [8];
  undefined2 local_10;
  undefined4 local_c;
  undefined1 local_8 [4];
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    if (param_5 == '\0') {
      iVar2 = FUN_00418360(param_1[6],param_2,local_8,0);
      if (iVar2 == 0) {
        iVar5 = -99;
      }
      else {
        FUN_0046f824(local_58,0,0x40);
        bVar3 = *(short *)(iVar2 + 4) != param_3;
        if (bVar3) {
          *(short *)(iVar2 + 4) = param_3;
        }
        iVar5 = (**(code **)*param_4)();
        if ((iVar5 != 0) && (*(int *)(iVar2 + 0xc) == -1)) {
          uVar4 = FUN_00416cf5();
          *(undefined4 *)(iVar2 + 0xc) = uVar4;
          bVar3 = true;
        }
        FUN_00416c4d(*(undefined4 *)(iVar2 + 0xc),param_4);
        if (!bVar3) {
          return;
        }
        if (*(int *)(iVar2 + 8) == -1) {
          return;
        }
        iVar5 = FUN_004181b3(local_18,*(int *)(iVar2 + 8));
        if (iVar5 == 0) {
          local_10 = *(undefined2 *)(iVar2 + 4);
          local_c = *(undefined4 *)(iVar2 + 0xc);
          FUN_00418223(local_18,*(undefined4 *)(iVar2 + 8));
        }
      }
    }
    else {
      iVar5 = -0x5b;
    }
    FUN_004659fc(iVar5);
  }
  return;
}

