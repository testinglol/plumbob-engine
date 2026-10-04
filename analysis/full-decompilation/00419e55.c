
void __thiscall
FUN_00419e55(int *param_1,int param_2,undefined4 param_3,short param_4,undefined4 param_5,
            undefined4 param_6,char param_7)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    iVar2 = -0x31;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (cVar1 != '\0') {
      puVar3 = (undefined4 *)FUN_00418d64(param_3,(int)param_4,param_6,0);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)FUN_00418ca9(param_3);
      }
      else {
        if (puVar3[3] == param_2) {
          puVar3[3] = 0;
        }
        iVar2 = FUN_0041a318(puVar3);
        if (iVar2 != 0) goto LAB_00419ed4;
        FUN_004131cb();
      }
      puVar3[1] = (int)param_4;
      if (param_7 == '\0') {
        *(undefined2 *)(puVar3 + 2) = 0;
      }
      else {
        *(undefined2 *)(puVar3 + 2) = 0x10;
      }
      *(ushort *)(puVar3 + 2) = CONCAT11((undefined1)param_6,*(undefined1 *)(puVar3 + 2));
      *(undefined2 *)((int)puVar3 + 10) = 0;
      puVar3[3] = param_2;
      FUN_0046f8e4(param_5);
      *puVar3 = 0xffffffff;
      return;
    }
    iVar2 = -0x2d;
  }
LAB_00419ed4:
  FUN_004659fc(iVar2);
  return;
}

