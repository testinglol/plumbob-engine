
uint __thiscall FUN_00457ba2(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xa4);
    break;
  case 1:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xa6);
    break;
  case 2:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xa8);
    break;
  case 3:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xaa);
    break;
  case 4:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xac);
    break;
  case 5:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xae);
    break;
  case 6:
    uVar1 = (uint)*(short *)(*(int *)(param_1 + 0x60) + 0xb0);
    break;
  case 7:
    uVar1 = *(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 1;
    break;
  case 8:
    uVar1 = (*(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 2) >> 1;
    break;
  case 9:
    uVar1 = (*(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 4) >> 2;
    break;
  case 10:
    uVar1 = (*(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 8) >> 3;
    break;
  case 0xb:
    uVar1 = (*(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 0x10) >> 4;
    break;
  case 0xc:
    uVar1 = (*(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 0x20) >> 5;
    break;
  case 0xd:
    uVar1 = (*(byte *)(*(int *)(param_1 + 0x60) + 0xb2) & 0x40) >> 6;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}

