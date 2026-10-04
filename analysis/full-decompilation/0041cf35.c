
void __thiscall
FUN_0041cf35(int *param_1,int param_2,undefined4 param_3,short param_4,undefined4 param_5,
            undefined4 param_6,char param_7)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    iVar4 = -0x31;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (cVar1 != '\0') {
      iVar2 = FUN_0041baf1(param_3,(int)param_4,param_6);
      if (iVar2 == 0) {
        iVar2 = FUN_0041be7a(param_3,0);
        iVar2 = FUN_0041b8c6(param_3,(int)param_4,param_6,iVar2 + 1);
      }
      else {
        if (*(int *)(iVar2 + 8) == param_2) {
          *(undefined4 *)(iVar2 + 8) = 0;
        }
        iVar4 = FUN_0041d3d0(iVar2);
        if (iVar4 != 0) goto LAB_0041cfb2;
        FUN_004131cb();
      }
      if (param_7 == '\0') {
        *(undefined1 *)(iVar2 + 2) = 0;
      }
      else {
        *(short *)(iVar2 + 2) =
             (short)CONCAT31((uint3)(byte)((ushort)*(undefined2 *)(iVar2 + 2) >> 8),0x10);
      }
      *(undefined2 *)(iVar2 + 4) = 0;
      *(int *)(iVar2 + 8) = param_2;
      FUN_0046f8e4(param_5);
      *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
      return;
    }
    iVar4 = -0x2d;
  }
LAB_0041cfb2:
  FUN_004659fc(iVar4);
  return;
}

