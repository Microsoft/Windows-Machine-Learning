#pragma once
#include <random>
#include <time.h>
#include "Common.h"
#include "ModelBinding.h"
#include <MemoryBuffer.h>
#include "Windows.AI.Machinelearning.Native.h"
#include "DirectXPackedVector.h"
#include "CommandLineArgs.h"
#include "OutputHelper.h"

using namespace winrt::Windows::Media;
using namespace winrt::Windows::Storage;
using namespace winrt::Windows::Storage::Streams;
using namespace winrt::Windows::AI::MachineLearning;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Graphics::DirectX;
using namespace winrt::Windows::Graphics::Imaging;
using namespace winrt::Windows::Graphics::DirectX::Direct3D11;
using namespace DirectX::PackedVector;

template <TensorKind T> struct TensorKindToArithmeticType
{
    static_assert(true, "No TensorKind mapped for given type!");
};
template <> struct TensorKindToArithmeticType<TensorKind::UInt8>
{
    typedef uint8_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Int8>
{
    typedef uint8_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::UInt16>
{
    typedef uint16_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Int16>
{
    typedef int16_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::UInt32>
{
    typedef uint32_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Int32>
{
    typedef int32_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::UInt64>
{
    typedef uint64_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Int64>
{
    typedef int64_t Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Boolean>
{
    typedef boolean Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Double>
{
    typedef double Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Float>
{
    typedef float Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::Float16>
{
    typedef float Type;
};
template <> struct TensorKindToArithmeticType<TensorKind::String>
{
    typedef winrt::hstring Type;
};

template <TensorKind T> struct TensorKindToPointerType
{
    static_assert(true, "No TensorKind mapped for given type!");
};
template <> struct TensorKindToPointerType<TensorKind::UInt8>
{
    typedef uint8_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::Int8>
{
    typedef uint8_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::UInt16>
{
    typedef uint16_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::Int16>
{
    typedef int16_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::UInt32>
{
    typedef uint32_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::Int32>
{
    typedef int32_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::UInt64>
{
    typedef uint64_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::Int64>
{
    typedef int64_t Type;
};
template <> struct TensorKindToPointerType<TensorKind::Boolean>
{
    typedef boolean Type;
};
template <> struct TensorKindToPointerType<TensorKind::Double>
{
    typedef double Type;
};
template <> struct TensorKindToPointerType<TensorKind::Float>
{
    typedef float Type;
};
template <> struct TensorKindToPointerType<TensorKind::Float16>
{
    typedef HALF Type;
};
template <> struct TensorKindToPointerType<TensorKind::String>
{
    typedef winrt::hstring Type;
};

template <TensorKind T> struct TensorKindToValue
{
    static_assert(true, "No TensorKind mapped for given type!");
};
template <> struct TensorKindToValue<TensorKind::UInt8>
{
    typedef TensorUInt8Bit Type;
};
template <> struct TensorKindToValue<TensorKind::Int8>
{
    typedef TensorInt8Bit Type;
};
template <> struct TensorKindToValue<TensorKind::UInt16>
{
    typedef TensorUInt16Bit Type;
};
template <> struct TensorKindToValue<TensorKind::Int16>
{
    typedef TensorInt16Bit Type;
};
template <> struct TensorKindToValue<TensorKind::UInt32>
{
    typedef TensorUInt32Bit Type;
};
template <> struct TensorKindToValue<TensorKind::Int32>
{
    typedef TensorInt32Bit Type;
};
template <> struct TensorKindToValue<TensorKind::UInt64>
{
    typedef TensorUInt64Bit Type;
};
template <> struct TensorKindToValue<TensorKind::Int64>
{
    typedef TensorInt64Bit Type;
};
template <> struct TensorKindToValue<TensorKind::Boolean>
{
    typedef TensorBoolean Type;
};
template <> struct TensorKindToValue<TensorKind::Double>
{
    typedef TensorDouble Type;
};
template <> struct TensorKindToValue<TensorKind::Float>
{
    typedef TensorFloat Type;
};
template <> struct TensorKindToValue<TensorKind::Float16>
{
    typedef TensorFloat16Bit Type;
};
template <> struct TensorKindToValue<TensorKind::String>
{
    typedef TensorString Type;
};

template <TensorKind T, typename PointerType, typename ArithmeticType > PointerType ConvertArithmeticTypeToPointerType(ArithmeticType value)
{
    static_assert(true, "No TensorKind mapped for given type!");
};
template <> uint8_t ConvertArithmeticTypeToPointerType<TensorKind::UInt8>(uint8_t value)
{
    return static_cast<uint8_t>(value);
};
template <> uint8_t ConvertArithmeticTypeToPointerType<TensorKind::Int8>(uint8_t value)
{
    return static_cast<uint8_t>(value);
};
template <> uint16_t ConvertArithmeticTypeToPointerType<TensorKind::UInt16>(uint16_t value)
{
    return static_cast<uint16_t>(value);
};
template <> int16_t ConvertArithmeticTypeToPointerType<TensorKind::Int16>(int16_t value)
{
    return static_cast<int16_t>(value);
};
template <> uint32_t ConvertArithmeticTypeToPointerType<TensorKind::UInt32>(uint32_t value)
{
    return static_cast<uint32_t>(value);
};
template <> int32_t ConvertArithmeticTypeToPointerType<TensorKind::Int32>(int32_t value)
{
    return static_cast<int32_t>(value);
};
template <> uint64_t ConvertArithmeticTypeToPointerType<TensorKind::UInt64>(uint64_t value)
{
    return static_cast<uint64_t>(value);
};
template <> int64_t ConvertArithmeticTypeToPointerType<TensorKind::Int64>(int64_t value)
{
    return static_cast<int64_t>(value);
};
template <> boolean ConvertArithmeticTypeToPointerType<TensorKind::Boolean>(boolean value)
{
    return static_cast<boolean>(value);
};
template <> double ConvertArithmeticTypeToPointerType<TensorKind::Double>(double value)
{
    return static_cast<double>(value);
};
template <> float ConvertArithmeticTypeToPointerType<TensorKind::Float>(float value)
{
    return static_cast<float>(value);
};
template <> HALF ConvertArithmeticTypeToPointerType<TensorKind::Float16>(float value)
{
    return XMConvertFloatToHalf(value);
};
template <> winrt::hstring ConvertArithmeticTypeToPointerType<TensorKind::String>(winrt::hstring value)
{
    return static_cast<winrt::hstring>(value);
};

namespace BindingUtilities
{
    static unsigned int seed = 0;
    static std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned int> randomBitsEngine;

    SoftwareBitmap GenerateGarbageImage(const TensorFeatureDescriptor& imageDescriptor, InputDataType inputDataType)
    {
        assert(inputDataType != InputDataType::Tensor);

        // We assume NCHW and NCDHW
        uint64_t width = imageDescriptor.Shape().GetAt(imageDescriptor.Shape().Size() - 1);
        uint64_t height = imageDescriptor.Shape().GetAt(imageDescriptor.Shape().Size() - 2);
        uint64_t channelCount = imageDescriptor.Shape().GetAt(1);
        uint64_t batchCount = imageDescriptor.Shape().GetAt(0);

        // If the batchCount is infinite, we can put as many images as we want
        if (batchCount >= ULLONG_MAX)
        {
            batchCount = 3;
        }

        // We have to create RGBA8 or BGRA8 images, so we need 4 channels
        uint32_t totalByteSize = static_cast<uint32_t>(width) * static_cast<uint32_t>(height) * 4;

        // Generate values for the image based on a seed
        std::vector<uint8_t> data(totalByteSize);
        randomBitsEngine.seed(seed++);
        std::generate(data.begin(), data.end(), randomBitsEngine);

        // Write the values to a buffer
        winrt::array_view<const uint8_t> dataView(data);
        InMemoryRandomAccessStream dataStream;
        DataWriter dataWriter(dataStream);
        dataWriter.WriteBytes(dataView);
        IBuffer buffer = dataWriter.DetachBuffer();

        // Create the software bitmap
        return SoftwareBitmap::CreateCopyFromBuffer(buffer, TypeHelper::GetBitmapPixelFormat(inputDataType),
                                                    static_cast<int32_t>(width), static_cast<int32_t>(height));
    }

    SoftwareBitmap LoadImageFile(const TensorFeatureDescriptor& imageDescriptor, InputDataType inputDataType,
                                 const hstring& filePath, const CommandLineArgs& args, uint32_t iterationNum)
    {
        assert(inputDataType != InputDataType::Tensor);

        // We assume NCHW and NCDHW
        uint64_t width = imageDescriptor.Shape().GetAt(imageDescriptor.Shape().Size() - 1);
        uint64_t height = imageDescriptor.Shape().GetAt(imageDescriptor.Shape().Size() - 2);
        uint64_t channelCount = imageDescriptor.Shape().GetAt(1);
        uint64_t batchCount = imageDescriptor.Shape().GetAt(0);

        try
        {
            // open the file
            StorageFile file = StorageFile::GetFileFromPathAsync(filePath).get();
            // get a stream on it
            auto stream = file.OpenAsync(FileAccessMode::Read).get();
            // Create the decoder from the stream
            BitmapDecoder decoder = BitmapDecoder::CreateAsync(stream).get();

            // If input dimensions are different from tensor input, then scale / crop while reading
            if (args.IsAutoScale() && (decoder.PixelHeight() != height || decoder.PixelWidth() != width))
            {
                if (!args.TerseOutput() || iterationNum == 0)
                    std::cout << std::endl
                              << "Binding Utilities: AutoScaling input image to match model input dimensions...";

                // Create a transform object with default parameters (no transform)
                auto transform = BitmapTransform();
                transform.ScaledHeight(static_cast<uint32_t>(height));
                transform.ScaledWidth(static_cast<uint32_t>(width));
                transform.InterpolationMode(args.AutoScaleInterpMode());

                // get the bitmap
                return decoder
                    .GetSoftwareBitmapAsync(TypeHelper::GetBitmapPixelFormat(inputDataType), BitmapAlphaMode::Ignore,
                                            transform, ExifOrientationMode::RespectExifOrientation,
                                            ColorManagementMode::DoNotColorManage)
                    .get();
            }
            else
            {
                // get the bitmap
                return decoder
                    .GetSoftwareBitmapAsync(TypeHelper::GetBitmapPixelFormat(inputDataType), BitmapAlphaMode::Ignore)
                    .get();
            }
        }
        catch (...)
        {
            std::cout << "BindingUtilities: could not open image file, make sure you are using fully qualified paths."
                      << std::endl;
            return nullptr;
        }
    }

    VideoFrame CreateVideoFrame(const SoftwareBitmap& softwareBitmap, InputBindingType inputBindingType,
                                InputDataType inputDataType, const IDirect3DDevice winrtDevice)
    {
        VideoFrame inputImage = VideoFrame::CreateWithSoftwareBitmap(softwareBitmap);

        if (inputBindingType == InputBindingType::GPU)
        {
            VideoFrame gpuImage =
                winrtDevice
                    ? VideoFrame::CreateAsDirect3D11SurfaceBacked(TypeHelper::GetDirectXPixelFormat(inputDataType),
                                                                  softwareBitmap.PixelWidth(),
                                                                  softwareBitmap.PixelHeight(), winrtDevice)
                    : VideoFrame::CreateAsDirect3D11SurfaceBacked(TypeHelper::GetDirectXPixelFormat(inputDataType),
                                                                  softwareBitmap.PixelWidth(),
                                                                  softwareBitmap.PixelHeight());

            inputImage.CopyToAsync(gpuImage).get();

            return gpuImage;
        }

        return inputImage;
    }

    std::vector<std::string> ReadCsvLine(std::ifstream& fileStream)
    {
        std::vector<std::string> elementStrings;
        // Read next line.
        std::string line;
        if (!std::getline(fileStream, line))
        {
            ThrowFailure(L"BindingUtilities: expected more input rows.");
        }

        // Split the line into strings for each value.
        std::istringstream elementsString(line);
        std::string elementString;
        while (std::getline(elementsString, elementString, ','))
        {
            elementStrings.push_back(elementString);
        }
        return elementStrings;
    }

    std::vector<std::string> ParseCSVElementStrings(const std::wstring& csvFilePath)
    {
        std::ifstream fileStream;
        fileStream.open(csvFilePath);
        if (!fileStream.is_open())
        {
            ThrowFailure(L"BindingUtilities: could not open data file.");
        }

        std::vector<std::string> elementStrings = ReadCsvLine(fileStream);

        return elementStrings;
    }

    template <TensorKind T>
    static ITensor CreateTensor(const CommandLineArgs& args, std::vector<std::string>& tensorStringInput,
                                TensorFeatureDescriptor& tensorDescriptor, SoftwareBitmap &softwareBitmap)
    {
        using TensorValue = typename TensorKindToValue<T>::Type;
        using ArithmeticType = typename TensorKindToArithmeticType<T>::Type;
        using PointerType = typename TensorKindToPointerType<T>::Type;

        // Map the incoming Tensor as a TensorNative to get the actual data buffer.
        auto tensorValue = TensorValue::Create(tensorDescriptor.Shape());

        com_ptr<ITensorNative> spTensorValueNative;
        tensorValue.as(spTensorValueNative);

        PointerType* actualData;
        uint32_t actualSizeInBytes;
        spTensorValueNative->GetBuffer(reinterpret_cast<BYTE**>(&actualData), &actualSizeInBytes);

        if (!args.CsvPath().empty())
        {
            if (tensorStringInput.size() != actualSizeInBytes / sizeof(PointerType))
            {
                throw hresult_invalid_argument(L"CSV input size/shape is different from what model expects");
            }

            // Write the elementStrings into the iTensorNative
            for (const auto &tensorString : tensorStringInput)
            {
                ArithmeticType value;
                std::stringstream(tensorString) >> value;
                *actualData = ConvertArithmeticTypeToPointerType<T,PointerType,ArithmeticType>(value);
                actualData++;
            }
        }
        else if (!args.ImagePath().empty())
        {
            // Get Pointers to the SoftwareBitmap buffers
            uint8_t *sbData = nullptr;
            uint32_t sbDataSize = 0;
            const BitmapBuffer sbBitmapBuffer(softwareBitmap.LockBuffer(BitmapBufferAccessMode::Read));
            winrt::Windows::Foundation::IMemoryBufferReference sbReference = sbBitmapBuffer.CreateReference();
            auto sbByteAccess = sbReference.as<::Windows::Foundation::IMemoryBufferByteAccess>();
            winrt::check_hresult(sbByteAccess->GetBuffer(&sbData, &sbDataSize));

            // Check to make sure the sizes are right
            const uint32_t imageHeight = softwareBitmap.PixelHeight();
            const uint32_t imageWidth = softwareBitmap.PixelWidth();
            const auto pixelFormat = softwareBitmap.BitmapPixelFormat();
            const uint32_t numChannels = 3;
            const uint32_t resultSize = imageHeight * imageWidth * numChannels;

            if (resultSize != actualSizeInBytes / sizeof(PointerType))
            {
                throw hresult_invalid_argument(L"Image Input size/shape is different from what model expects");
            }

            auto factors = args.InputImagePreprocessFactors();
            float channelFactors[3] = { factors.Red, factors.Green, factors.Blue };
            if (BitmapPixelFormat::Bgra8 == pixelFormat)
            {
                channelFactors[0] = factors.Blue;
                channelFactors[1] = factors.Green;
                channelFactors[2] = factors.Red;
            }
            else if (BitmapPixelFormat::Rgba8 != pixelFormat)
            {
                throw hresult_invalid_argument(L"PreprocessImageToTensor: Unhandled SoftwareBitmap pixel format");
            }

            //Roll the array correctly for the tensor
            for (uint32_t i = 0, count = 0; i < imageHeight * imageWidth; ++i, count += numChannels + 1)
            {
                actualData[i] = ConvertArithmeticTypeToPointerType<T, PointerType, ArithmeticType>(
                    static_cast<ArithmeticType>((sbData[count] - channelFactors[0]) / factors.Scale));
                actualData[i + imageHeight * imageWidth] = ConvertArithmeticTypeToPointerType<T, PointerType, ArithmeticType>(
                    static_cast<ArithmeticType>((sbData[count + 1] - channelFactors[1]) / factors.Scale));
                actualData[i + imageHeight * imageWidth * 2] = ConvertArithmeticTypeToPointerType<T, PointerType, ArithmeticType>(
                    static_cast<ArithmeticType>((sbData[count + 2] - channelFactors[2]) / factors.Scale));
            }
        }
        else if (args.IsGarbageInput())
        {
            std::vector<int64_t> vecShape = {};
            auto tensorDescriptorShape = tensorDescriptor.Shape();
            for (UINT dim = 0; dim < tensorDescriptorShape.Size(); dim++)
            {
                INT64 dimSize = tensorDescriptorShape.GetAt(dim);
                if (dimSize > 0) // If the dimension is greater than 0, then it is known.
                {
                    vecShape.push_back(dimSize);
                }
                else // otherwise, make sure that the dimension is -1, representing free dimension. If not, then it's an
                     // invalid model.
                {
                    if (dimSize == -1)
                    {
                        vecShape.push_back(1);
                    }
                    else
                    {
                        throw hresult_invalid_argument(L"Failed to create a tensor with an unknown dimension of: " +
                                                       dimSize);
                    }
                }
            }
            auto tensorValue = TensorValue::Create(vecShape);

            com_ptr<ITensorNative> spTensorValueNative;
            tensorValue.as(spTensorValueNative);

            BYTE* actualData;
            uint32_t actualSizeInBytes;
            spTensorValueNative->GetBuffer(
                &actualData, &actualSizeInBytes); // Need to GetBuffer to have CPU memory backing tensorValue
        }
        else
        {
            // Creating Tensors for Input Images haven't been added yet.
            throw hresult_not_implemented(L"Creating Tensors for Input Images haven't been implemented yet!");
        }

        return tensorValue;
    }

    // Binds tensor floats, ints, doubles from CSV data.
    ITensor CreateBindableTensor(
        const ILearningModelFeatureDescriptor& description,
        InputDataType inputDataType,
        const CommandLineArgs &args,
        uint32_t iterationNum)
    {
        auto name = description.Name();
        auto tensorDescriptor = description.try_as<TensorFeatureDescriptor>();

        if (!tensorDescriptor)
        {
            std::cout << "BindingUtilities: Input Descriptor type isn't tensor." << std::endl;
            throw;
        }

        ITensor tensor;
        SoftwareBitmap softwareBitmap(nullptr);
        std::vector<std::string> elementStrings;
        if (!args.CsvPath().empty())
        {
            elementStrings = ParseCSVElementStrings(args.CsvPath());
        }
        else if (!args.ImagePath().empty())
        {
            softwareBitmap = LoadImageFile(tensorDescriptor, inputDataType, args.ImagePath().c_str(), args, iterationNum);
        }
        switch (tensorDescriptor.TensorKind())
        {
            case TensorKind::Undefined:
            {
                std::cout << "BindingUtilities: TensorKind is undefined." << std::endl;
                throw hresult_invalid_argument();
            }
            case TensorKind::Float:
            {
                tensor = CreateTensor<TensorKind::Float>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::Float16:
            {
                tensor = CreateTensor<TensorKind::Float16>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::Double:
            {
                tensor = CreateTensor<TensorKind::Double>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::Int8:
            {
                tensor = CreateTensor<TensorKind::Int8>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::UInt8:
            {
                tensor = CreateTensor<TensorKind::UInt8>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::Int16:
            {
                tensor = CreateTensor<TensorKind::Int16>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::UInt16:
            {
                tensor = CreateTensor<TensorKind::UInt16>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::Int32:
            {
                tensor = CreateTensor<TensorKind::Int32>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::UInt32:
            {
                tensor = CreateTensor<TensorKind::UInt32>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::Int64:
            {
                tensor = CreateTensor<TensorKind::Int64>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            case TensorKind::UInt64:
            {
                tensor = CreateTensor<TensorKind::UInt64>(args, elementStrings, tensorDescriptor, softwareBitmap);
            }
            break;
            default:
                std::cout << "BindingUtilities: TensorKind has not been implemented." << std::endl;
                throw hresult_not_implemented();
        }

        return tensor;
    }

    ImageFeatureValue CreateBindableImage(const ILearningModelFeatureDescriptor& featureDescriptor,
                                          const std::wstring& imagePath, InputBindingType inputBindingType,
                                          InputDataType inputDataType, const IDirect3DDevice winrtDevice,
                                          const CommandLineArgs& args, uint32_t iterationNum)
    {
        auto imageDescriptor = featureDescriptor.try_as<TensorFeatureDescriptor>();
        if (!imageDescriptor)
        {
            std::cout << "BindingUtilities: Input Descriptor type isn't tensor." << std::endl;
            throw;
        }

        auto softwareBitmap =
            imagePath.empty() ? GenerateGarbageImage(imageDescriptor, inputDataType)
                              : LoadImageFile(imageDescriptor, inputDataType, imagePath.c_str(), args, iterationNum);

        auto videoFrame = CreateVideoFrame(softwareBitmap, inputBindingType, inputDataType, winrtDevice);

        return ImageFeatureValue::CreateFromVideoFrame(videoFrame);
    }

    template <typename K, typename V>
    void OutputSequenceBinding(IMapView<hstring, winrt::Windows::Foundation::IInspectable> results, hstring name)
    {
        auto map = results.Lookup(name).as<IVectorView<IMap<K, V>>>().GetAt(0);
        auto iter = map.First();

        K maxKey = -1;
        V maxVal = -1;

        while (iter.HasCurrent())
        {
            auto pair = iter.Current();
            if (pair.Value() > maxKey)
            {
                maxVal = pair.Value();
                maxKey = pair.Key();
            }
            iter.MoveNext();
        }
        std::cout << " " << maxKey << " " << maxVal << std::endl;
    }

    void PrintOrSaveEvaluationResults(const LearningModel& model, const CommandLineArgs& args,
                                      const IMapView<hstring, winrt::Windows::Foundation::IInspectable>& results,
                                      OutputHelper& output, int iterationNum)
    {
        for (auto&& desc : model.OutputFeatures())
        {
            if (desc.Kind() == LearningModelFeatureKind::Tensor)
            {
                std::wstring name(desc.Name());
                if (args.IsSaveTensor() && args.SaveTensorMode() == "First" && iterationNum > 0)
                {
                    return;
                }
                if (args.IsSaveTensor())
                {
                    output.SetDefaultCSVIterationResult(iterationNum, args, name);
                }
                void* tensor;
                uint32_t uCapacity;
                com_ptr<ITensorNative> itn = results.Lookup(desc.Name()).as<ITensorNative>();
                HRESULT(itn->GetBuffer(reinterpret_cast<BYTE**>(&tensor), &uCapacity));
                int size = 0;
                unsigned int topK = args.TopK();
                std::vector<std::pair<float, int>> maxKValues;
                std::ofstream fout;
                if (args.IsSaveTensor())
                {
                    fout.open(output.getCsvFileNamePerIterationResult(), std::ios_base::app);
                    fout << "Index"
                         << ","
                         << "Value" << std::endl;
                }
                TensorFeatureDescriptor tensorDescriptor = desc.as<TensorFeatureDescriptor>();
                TensorKind tensorKind = tensorDescriptor.TensorKind();
                switch (tensorKind)
                {
                    case TensorKind::String:
                    {
                        if (!args.IsGarbageInput())
                        {
                            auto resultVector = results.Lookup(desc.Name()).as<TensorString>().GetAsVectorView();
                            auto output = resultVector.GetAt(0).data();
                            std::wcout << " Result: " << output << std::endl;
                        }
                    }
                    break;
                    case TensorKind::Float16:
                    {
                        output.ProcessTensorResult<HALF>(args, tensor, uCapacity, maxKValues, fout, topK);
                    }
                    break;
                    case TensorKind::Float:
                    {
                        output.ProcessTensorResult<float>(args, tensor, uCapacity, maxKValues, fout, topK);
                    }
                    break;
                    case TensorKind::Int64:
                    {
                        auto resultVector = results.Lookup(desc.Name()).as<TensorInt64Bit>().GetAsVectorView();
                        if (!args.IsGarbageInput())
                        {
                            auto output = resultVector.GetAt(0);
                            std::wcout << " Result: " << output << std::endl;
                        }
                    }
                    break;
                    default:
                    {
                        std::cout << "BindingUtilities: output type not implemented.";
                    }
                    break;
                }
                if (args.IsSaveTensor())
                {
                    fout.close();
                    for (auto& pair : maxKValues)
                    {
                        auto maxValue = pair.first;
                        auto maxIndex = pair.second;
                        std::string iterationResult =
                            "Index: " + std::to_string(maxIndex) + "; Value: " + std::to_string(maxValue);
                        output.SaveResult(iterationNum, iterationResult,
                                          static_cast<int>(hash_data(tensor, uCapacity)));
                    }
                }
                if (!args.IsGarbageInput() && iterationNum == 0)
                {
                    std::wcout << "Outputting top " << args.TopK() << " values" << std::endl;
                    std::wcout << "Feature Name: " << name << std::endl;
                    for (auto& pair : maxKValues)
                    {
                        auto maxValue = pair.first;
                        auto maxIndex = pair.second;
                        std::wcout << " index: " << maxIndex << ", value: " << maxValue
                                   << std::endl;
                    }
                }
            }
            else if (desc.Kind() == LearningModelFeatureKind::Sequence)
            {
                auto seqDescriptor = desc.as<SequenceFeatureDescriptor>();
                auto mapDescriptor = seqDescriptor.ElementDescriptor().as<MapFeatureDescriptor>();
                auto keyKind = mapDescriptor.KeyKind();
                auto valueKind = mapDescriptor.ValueDescriptor();
                auto tensorKind = valueKind.as<TensorFeatureDescriptor>().TensorKind();
                switch (keyKind)
                {
                    case TensorKind::Int64:
                    {
                        OutputSequenceBinding<int64_t, float>(results, desc.Name());
                    }
                    break;
                    case TensorKind::Float:
                    {
                        OutputSequenceBinding<float, float>(results, desc.Name());
                    }
                    break;
                }
            }
        }
    }
}; // namespace BindingUtilities
